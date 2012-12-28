#include "EditMenu.h"

bool EditMenu::runEdit(uint8_t index)
{
	startBlinkOff(index);
	uint8_t key;
	do {
		key =  keyboard.getPressedWithSpeed();
		if(key == BUTTON_DEC || key == BUTTON_INC) {
			editItem(index, key);
			startBlinkOn(index);
		}
	display();
	} while(key != BUTTON_STOP && key != BUTTON_START);

	stopBlink();
	display();
	return key == BUTTON_START;
}
