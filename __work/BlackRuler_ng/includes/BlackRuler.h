//Visual studio interface

#define RULE(ReturnType) ReturnType
#define CONDITION( ... )

#define Choose( ... )
#define ChooseFirst( ... )
#define Delay(__UID, time, command, ... )
#define When(__UID, time, condition, command)
#define While(condition, command)
#define Not(expression) !expression

//game types
typedef void* unknown;
typedef float number;
typedef  char* string;

//game objects
typedef struct object
{
	//generic object structure 
	//toDO replace by class defination
} Object;

typedef struct color
{
	number red;
	number green;
	number blue;
	number alpha;
} color;

typedef struct rotator
{
	number heading;
	number pitch;
	number bank;
} rotator;

typedef struct vector
{
	number x;
	number y;
	number z;
} vector;

typedef struct matrix
{
	//empty struct cos in game this is a solid object
} matrix;

typedef struct list
{
	//dummy type for list defination
} list; 

//Variable manager
//Math
number ceil(number a);
number cos(number x);
number exp(number x);
number floor(number a);
number log(number x);
number max(number a, number b);
number min(number a, number b);
number pow(number x, number y);
number rnd();
number rnd(number a, number b);
number round(number a);
number sin(number x);
number sqrt(number x);
rotator* rot(number heading, number pitch, number bank);
rotator* v2Rot(vector* vec);
vector* r2Vec(rotator* rot);
number rEqu(rotator* rot1, rotator* rot2);
rotator* rNull();
matrix* xfIdent();
matrix* xfTran(vector* position);
matrix* xfTran(number dx, number fy, number dz);
matrix* xfRotX(number angle);
matrix* xfRotY(number angle);
matrix* xfRotZ(number angle);
matrix* xfRot(rotator* rotator);
matrix* xfRot(number head, number pitch, number bank);
matrix* xfScale(number sx, number sy, number sz);
matrix* xfInv(matrix* xf);
matrix* xfTran(matrix* xf);
#define xfMul( xf1, xf2, ... )
vector* vec(number x, number y, number z);
vector* vNull();
vector* vRandomOrth(vector* vec);
vector* vRandomDir();
number vLen(vector* vec);
number vSqLen(vector* vec);
vector* vNorm(vector* vec);
vector* vNeg(vector* vec);
vector* vAdd(vector* vec1, vector* vec2);
vector* vSub(vector* vec1, vector* vec2);
vector* vNul(number num, vector* vec);
number vDot(vector* vec1, vector* vec2);
vector* vCross(vector* vec1, vector* vec2);
number vEqu(vector* vec1, vector* vec2);
vector* vxForm(vector* vec, matrix* xf);

//strings
number sLen(string str);
string sCat(string str1, string str2);
string sSub(string str, number start, number length);
string sNum(number num, number prec);
string sNumPad(number num, number width);
number sCmp(number str1, number str2);
number siCmp(number str1, number str2);


//color
color* col(number red, number green, number blue, number alpha = 1.f);	
color* col(number brightness);
color* cHeat(number heat);
color* cPlanck(number heat);
color* cInv(color* col);
color* cAdd(color* col1, color* col2);
color* cAddA(color* col1, color* col2);
color* cMul(color* col1, color* col2);
color* cMul(number num, color* col);
color* cLerp(color* col1, color* col2, number fact);
color* cBrig(color* col);
number cEqu(color* col1, color* col2);

//objects
#define getVal(obj, name) obj->name
#define setVal(obj, name, value) obj->name = value;
number isName(object* obj, string name);

//selection
void addItem(list list, object* obj);
void addList(list list1, list list2);
number allNumOf(list list);
void copy(list list1, list list2);
#define copyIf(to_list, from_list, condition)
void deleteSelect(list list);
#define deselect(list, condition)
void DIM(list list, int size);
void empty(list list);
void clearSelect(list list);
#define execList(list, condition)
#define findUnder(list, root, condition)
unknown firstNotScanned(list list, int race); //todo race to object; unknown to ship
list getFreeSel();
unknown getN(list list, int index);
int indexOf(list list, object* obj);
int indexOf(list list, number obj);
int inSelection(list list, object* obj);
#define maxList(list, n, condition)
int numOf(list list);
object* pick(list list);
object* pickFirst(list list);
#define pickMax(list, condition)
unknown pickN(list list, int index);
void RemoveFirst(list list);
void RemoveItem(list list, object* obj);
#define select(list, condition)
#define selectBoats(list, condition)
#define selectDevices(list, ship, condition)
#define selectEx(condition, command)
#define selectShips(list, condition)
#define setWeightMul(list, mul, condition)
void setN(list list, int index, unknown value);
void subList(list list1, list list2);

//events
#define call(rule, ... )
#define eventEx(rule, ... )
#define localEvent(rule)
#define localEvent(rule, ... )
#define mEvent(rule, ...)
#define pEvent(rule, ...)
#define return(var) return var
#define rootEvent(rule, ...)
#define timer(rule, time, ... )
#define startTimer(rule, time, ... )
#define uCall(rule, ... )
void enableGUIEvents(int enable);
void RequestFiredEvent(unknown weapon, int request);



