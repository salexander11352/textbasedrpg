/*
 *	OS-Friendly Clear/Pause helper functions, 
 * among others.
 *
 */

void sys_clear() {
#ifdef _WIN32
	system("cmd /c cls");
#else // Assume POSIX
	system("clear");
#endif
}

void sys_pause() {
	std::cout << "Press enter to continue... ";
	std::cin.ignore();
}

void sys_pause( std::string message ) {
	std::cout << message;
	std::cin.ignore();
}