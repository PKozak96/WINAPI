#include <windows.h>


LPSTR NazwaKlasy = "wc";
MSG Komunikat;
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )

{
	/* WYPELNIANIE KLASY OKNA */

	WNDCLASSEX wc; 				
    wc.cbSize = sizeof( WNDCLASSEX );
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );		//DUZA ikonka okna aplikacji
	wc.hCursor = LoadCursor( NULL, IDC_ARROW );			//zaladowanie kursora myszki oraz jego ksztalt
	wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );	//tlo okienka (szare)
	wc.lpszMenuName = NULL;
	wc.lpszClassName = NazwaKlasy;
	wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );		//mala ikonka aplikacji
	
	/* REJESTRACJA KLASY OKNA */
	RegisterClassEx (&wc);
	
	/* TWORZENIE OKNA */
	HWND hWnd = CreateWindowEx (WS_EX_WINDOWEDGE, wc, "Okienko numer1", WS_CAPTION, CW_USEDEFAULT, CW_USEDEFAULT, 
	1000, 800, NULL, NULL, hInstance, NULL)
	
	/* WYSWIETLENIE OKNA */
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	
	/* PETLA KOMUNIKATOW */
     	while( GetMessage( & Komunikat, NULL, 0, 0 ) )
   {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
   }

   return Komunikat.wParam;
	
	
	

}







	
int i = MessageBox( NULL, "To jest wiadomoœæ.", "Wiadomoœæ", MB_OKCANCEL );

switch (i)
{
	
	case IDOK:
		Beep(500, 500);
		break;
	case IDCANCEL:
		Beep(100, 100);
		
}





	return 0;
