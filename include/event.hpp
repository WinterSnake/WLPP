/*

*/

namespace WL
{
	enum class Key
	{
		NONE = -1,
		// Lettes
		A = 1, B, C, D, E, F, G, H, I, J, K, L, M,
		N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		// Numericals
		D0, D1, D2, D3,	D4,
		D5, D6, D7, D8, D9,
		// Numpad
		N0, N1, N2, N3, N4,
		N5, N6, N7, N8, N9,
		// Functions Keys
		F1, F2, F3, F4, F5, F6,
		F7, F8, F9, F10, F11, F12,
		// Miscellaneous
		DOWN, LEFT, RIGHT, UP
	};

	struct Event
	{
		enum class TYPE
		{
			END_LOOP = -1,
			KEY_PRESS = 1,
			KEY_RELEASE,
		} type;

		// Operator Overload
		operator bool() const;
	};
}
