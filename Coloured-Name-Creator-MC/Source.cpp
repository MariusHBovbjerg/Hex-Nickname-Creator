#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;


float setGradientResolution(int nameSize, int gradientSize) {
	if (nameSize > gradientSize) {
		return ceil((float)nameSize / (float)gradientSize);

	}
	else {
		return 1;
			
	}
}

string buildUserName(string name, vector<string> colors, string code) {
	string nameTemp;
	const float gradientRes = setGradientResolution(name.size(), colors.size());
	int colorIndex = 0;
	int power = 0;
	for (size_t i = 1; i != name.size() - power + 1; i++) {

		nameTemp = nameTemp + "&#" + colors[colorIndex] + code + name.at(i + power - 1);

		if (i / gradientRes == 1) {
			colorIndex++;
			power = power + i;
			i = 0;
		}
	}
	return nameTemp;
}

vector<string> fetchcolors(const string url) {

	vector<string> c{};

	string intermediate = url.substr(url.find_last_of('/')+1, url.size());

	int stringSize = intermediate.size() / 7 + 1;

	for (size_t i = 0; i < stringSize; ++i) {

		string shard = intermediate.substr(0, intermediate.find_first_of('-'));

		if (i < (stringSize-1)) {

			string temp = intermediate.substr(7);

			intermediate.assign(temp);
		}

		c.push_back(shard);

	}
	
	return c;
}

string createUsername(int setting, string name, vector<string> colors) {

	switch (setting) {

	case 1:
		
		return buildUserName(name, colors, "");

		break;
	case 2:
		
		return buildUserName(name, colors, "&l");

		break;
	case 3:

		return buildUserName(name, colors, "&n");

		break;
	case 4:

		return buildUserName(name, colors, "&o");

		break;
	case 5:

		return buildUserName(name, colors, "&m");

		break;
	case 6:

		return buildUserName(name, colors, "&l&n");

		break;
	case 7:

		return buildUserName(name, colors, "&l&o");

		break;
	case 8:

		return buildUserName(name, colors, "&l&m");

		break;
	case 9:

		return buildUserName(name, colors, "&n&o");

		break;
	case 10:

		return buildUserName(name, colors, "&n&m");

		break;
	case 11:

		return buildUserName(name, colors, "&m&o");

		break;
	case 12:

		return buildUserName(name, colors, "&l&n&o");

		break;
	case 13:

		return buildUserName(name, colors, "&l&n&m");

		break;
	case 14:

	
		return buildUserName(name, colors, "&l&o&m");

		break;
	case 15:

		return buildUserName(name, colors, "&n&o&m");

		break;
	case 16:

		return buildUserName(name, colors, "&l&n&o&m");

		break;
	}
}

void placeInClipboard(string name) {
	OpenClipboard(0);

	EmptyClipboard();

	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, name.size() + 1);

	if (!hg) {

		CloseClipboard();
		return;
	}

	memcpy(GlobalLock(hg), name.c_str(), name.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}

int main(void) {
	
	string url;
	string urlReq = "https://coolors.co/";
	string name;
	int setting;

	cout << "Type coolors.co URL:" << endl;
	cin >> url;
	cout << endl;

	while (url.find(urlReq)) {
		cout << "Type coolors.co URL:" << endl;
		cin >> url;
		cout << endl;
	}

	cout << "Type your username (beware: No guarantee the game will accept the name length." << endl
		<< "If it fails, try shortening the name you type here)" << endl;
	cin >> name;
	cout << endl;

	while (name=="") {
		cout << "Type your username (beware: No guarantee the game will accept the name length." << endl
			<< "If it fails, try shortening the name you type here)" << endl;
		cin >> name;
		cout << endl;
	}

	cout << "Choose your setting:" << endl
		<< "1: Coloured" << endl

		<< "2: Bold & Coloured" << endl
		<< "3: Underlined & Coloured" << endl
		<< "4: Italic & Coloured" << endl
		<< "5: Strike-Through & Coloured" << endl

		<< "6: Bold & Underlined & Coloured" << endl
		<< "7: Bold & italic & Coloured" << endl
		<< "8: Bold & Strike-Through & Coloured" << endl
		<< "9: Underlined & italic & Coloured" << endl
		<< "10: Underlined & Strike-Through & Coloured" << endl
		<< "11: italic & Strike-Through & Coloured" << endl

		<< "12: Bold & Underlined & Italic & Coloured" << endl
		<< "13: Bold & Underlined & Stike-Trough & Coloured" << endl
		<< "14: Bold & Italic & Strike-Trough & Coloured" << endl
		<< "15: Underlined & Italic & Strike-Trough & Coloured" << endl

		<< "16: Bold & Underlined & Italic & Strike-Through & Coloured" << endl;

	cin >> setting;
	cout << endl;

	while (setting < 1 || setting > 16) {
		cout << setting << " is an invalid option choice." << endl;
		cout << "Choose your setting:" << endl
			<< "1: Coloured" << endl

			<< "2: Bold & Coloured" << endl
			<< "3: Underlined & Coloured" << endl
			<< "4: Italic & Coloured" << endl
			<< "5: Strike-Through & Coloured" << endl

			<< "6: Bold & Underlined & Coloured" << endl
			<< "7: Bold & italic & Coloured" << endl
			<< "8: Bold & Strike-Through & Coloured" << endl
			<< "9: Underlined & italic & Coloured" << endl
			<< "10: Underlined & Strike-Through & Coloured" << endl
			<< "11: italic & Strike-Through & Coloured" << endl

			<< "12: Bold & Underlined & Italic & Coloured" << endl
			<< "13: Bold & Underlined & Stike-Trough & Coloured" << endl
			<< "14: Bold & Italic & Strike-Trough & Coloured" << endl
			<< "15: Underlined & Italic & Strike-Trough & Coloured" << endl

			<< "16: Bold & Underlined & Italic & Strike-Through & Coloured" << endl;

		cin >> setting;
		cout << endl;
	}

	vector<string> c;

	c = fetchcolors(url);
	name = createUsername(setting, name, c);
	name = "/nick " + name;

	placeInClipboard(name);
	
	cout << "Your new nickname command has been placed into your clipboard, just ctrl + v, ingame :)" << endl;
	Sleep(10 * 1000);
	return 0;
}