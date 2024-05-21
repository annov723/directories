/*
Celem zadania jest rozszerzenie przygotowanego na dzisiejsze zajęcia projektu o klasy SymbolicLink, User.
Konieczna będzie też implementacja funkcjonalności takich jak:
  Implementacja metody performAsyncUserSearch() która wykorzystuje std::async to równoległego przeszukiwania naszego systemu plików.
  Jak widzicie - performAsyncUserSearch() może przeszukiwać tylko pliki do których użytkownik ma dostęp - LEPSZYM rozwiązaniem (z punktu widzenia oceny) będzie zapewnienie restrykcji na plikach/folderach/linkach, 
  żeby zobaczyć kto ma do nich dostęp niż po prostu sprawdzać od katalogu użytkownika w dół - ale to też będzie akceptowalne (ale pierwsza opcja lepiej widziana przy ocenianiu).

  Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
  oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.


  Program wyjściowy powinien składać się z czytelnego kodu. Powinna być spełniona zasada D.R.Y. - Don’t Repeat Yourself.

  Zadania oceniane są wg algorytmu:

      Warunkiem przystąpienia do oceniania programu jest jego poprawna kompilacja (bez błędów).
      Dokumentacja - 1 pkt.
      Poprawna kompilacja (bez ostrzeżeń) - 2 pkt.
      Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci itp.) - 3 pkt.
      Ocena kodu (pod względem projektowym, zgodności z OOP, przejrzystości oraz sposobu implantacji) - maks. 4 pkt.


  Programy niezgodne z tematem/celem zadania, 
  ale kompilujące się (i dające potencjalnie "poprawne" wyjście) będą oceniane na 0 pkt.


*/

//TODO: Add Your includes
#include "FSElement.h"
#include "File.h"
#include "Dir.h"
#include "Link.h"
#include "User.h"

int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home; // dodajemy do kat TOP podkatalog
  *home += new Dir("ewa");
  *home += new File("proj.descr");
  home->add(new File("proj.files.repo") );
  home->add(new Dir("adam") );
  
  top->findDir("ewa")->add( new Dir("Desk") );

  Dir* ewaDir = home->findDir("ewa");  
  Dir* adamDir = home->findDir("ewa");  
  *ewaDir += new File("pict.jpg");
  *adamDir += new File("pict.jpg");
  top->findDir("ewa")->add( new Dir("work") );

  // Adding a symbolic link for demonstration
  Link* link = new Link("home_link", home);
  *top += link;

  std::cout << *top << std::endl;

  std::cout << "--------------" << std::endl;
  top->listDirs(1);
  std::cout << "--------------" << std::endl;
  top->listDirs(2);


  // Create users
  User* ewa = new User("ewa", ewaDir);
  User* adam = new User("adam", home->findDir("adam"));

  // Perform an asynchronous search for files named "pict.jpg" as user "ewa"
  std::vector<FSElement*> ewaSearchResults = performAsyncUserSearch(ewa, "pict.jpg");

  std::cout << "Search results for 'pict.jpg' as user 'ewa':" << std::endl;
  for (FSElement* elem : ewaSearchResults) {
      std::cout << elem->getPath() << " (" << (dynamic_cast<Dir*>(elem) ? "DIR" : "FILE") << ")" << std::endl;
  }

  delete top;
  delete ewa;
  delete adam;
}

/*
. (DIR)
  home (DIR)
    ewa (DIR)
      Desk (DIR)
      pict.jpg (FILE)
      work (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)
      pict.jpg (FILE)
  home_link (LINK to DIR home)  // This represents the symbolic link to 'home'

--------------
. home 
--------------
. home ewa adam

Search results for 'pict.jpg' as user 'ewa':
home ewa pict.jpg (FILE)
home_link eva pict.jpg (FILE)
// Bonus zadanie: - przedstaw home_link jako alias home w jakiś sposób.
*/