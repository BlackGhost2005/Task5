//#include <iostream>
//#include <cassert>
//using namespace std;
//
//class Computer {
//	char* _model;
//	char* _color;
//	char* _CPU; // Intel Core i7-8550U
//	static int _staticId_;
//	int _id;
//	int _year;
//	short _RAM;
//	int _space; // (Hard disc or SSD)
//
//public:
//	//Constructors
//	Computer() :_model(), _color(), _CPU(), _year(), _RAM(), _space() { _id = ++_staticId_; }
//	Computer(const char* _model, const char* _color, const char* _CPU, size_t _year, short _RAM, size_t _space) {
//		_id = ++_staticId_;
//		setModel(_model);
//		setColor(_color);
//		setCPU(_CPU);
//		setYear(_year);
//		setRAM(_RAM);
//		setSpace(_space);
//	}
//
//	Computer(const Computer& other) :_id(++_staticId_) {
//		setModel(other._model);
//		setColor(other._color);
//		setCPU(other._CPU);
//		setYear(other._year);
//		setRAM(other._RAM);
//		setSpace(other._space);
//	}
//
//	// Get Methods
//	char* getModel() { return this->_model; }
//	char* getColor() { return this->_color; }
//	char* getCPU() { return this->_CPU; }
//	int getID() { return this->_id; }
//	int getYear() { return this->_year; }
//	short getRAM() { return this->_RAM; }
//	int getSpace() { return this->_space; }
//
//
//	// Set Methods
//	void setModel(const char* model) {
//		if (strlen(model) < 2)
//			assert(!"Model minimum 2 herf olmalidir !");
//
//		if (this->_model != nullptr) {
//			delete[]this->_model;
//		}
//		int len = strlen(model);
//		this->_model = new char[len + 1];
//		strcpy_s(this->_model, len + 1, model);
//	}
//
//	void setColor(const char* color) {
//		if (strlen(color) < 2)
//			assert(!"Color minimum 2 herf olmalidir !");
//
//		if (this->_color != nullptr) {
//			delete[]this->_color;
//		}
//		int len = strlen(color);
//		this->_color = new char[len + 1];
//		strcpy_s(this->_color, len + 1, color);
//	}
//
//	void setCPU(const char* CPU) {
//		if (strlen(CPU) < 2)
//			assert(!"CPU minimum 2 simvol olmalidir !");
//
//		if (this->_CPU != nullptr) {
//			delete[]this->_CPU;
//		}
//		int len = strlen(CPU);
//		this->_CPU = new char[len + 1];
//		strcpy_s(this->_CPU, len + 1, CPU);
//	}
//
//	void setYear(int year) {
//		if (year >= 2000) {
//			this->_year = year;
//			return;
//		}
//		assert(!"IL sehvdir !");
//	}
//
//	void setRAM(short RAM) {
//		if (RAM >= 4) {
//			this->_RAM = RAM;
//			return;
//		}
//		assert(!"RAM sehvdir !");
//	}
//
//	void setSpace(int space) {
//		if (space >= 64) {
//			this->_space = space;
//			return;
//		}
//		assert(!"Space sehvdir !");
//	}
//
//	Computer& operator=(const Computer& other) {
//		setModel(other._model);
//		setColor(other._color);
//		setCPU(other._CPU);
//		setYear(other._year);
//		setRAM(other._RAM);
//		setSpace(other._space);
//
//		return *this;
//	}
//
//	void print() {
//
//		cout << "\tID: " << this->_id << endl;
//		cout << "Model: " << this->_model << endl;
//		cout << "Color: " << this->_color << endl;
//		cout << "CPU: " << this->_CPU  << endl;
//		cout << "Year: " << this->_year << endl;
//		cout << "RAM: " << this->_RAM << endl;
//		cout << "Space: " << this->_space << endl;
//		cout << "--------------------------------------------------------" << endl;
//	}
//
//	~Computer() {
//		delete[]_model;
//		delete[]_color;
//		delete[]_CPU;
//	}
//};
//
//int Computer::_staticId_ = 0;
//
//
//
//class CompStore {
//	char* _name;
//	Computer** _computers;
//	int _count;
//
//public:
//	//Constructors
//	CompStore(const char* _name, Computer**& _computers, int _count) {
//		setName(_name);
//		setComputers(_computers, _count);
//	}
//
//	CompStore(const CompStore& other) {
//		if (this != &other) {
//			setName(other._name);
//
//			this->_count = other._count;
//			this->_computers = new Computer* [_count];
//
//			for (size_t i = 0; i < this->_count; i++) {
//				this->_computers[i] = new Computer(*other._computers[i]);
//			}
//		}
//	}
//
//	// Get Methods
//	char* getName() { return this->_name; }
//	Computer** getComputers() { return this->_computers; }
//	int getCount() { return this->_count; }
//
//	//Set Methods
//	void setName(const char* name) {
//		if (strlen(name) < 2)
//			assert(!"Ad sehvdir !");
//
//		if (this->_name != nullptr) {
//			delete[]this->_name;
//		}
//		int len = strlen(name);
//		this->_name = new char[len + 1];
//		strcpy_s(this->_name, len + 1, name);
//	}
//
//	void setComputers(Computer**& computers, int count) {
//		for (size_t i = 0; i < this->_count; i++) {
//			delete this->_computers[i];
//		}
//		delete[] this->_computers;
//
//		this->_computers = new Computer * [count];
//		for (size_t i = 0; i < count; i++) {
//			this->_computers[i] = new Computer(computers[i]->getModel(), computers[i]->getColor(), computers[i]->getCPU(), computers[i]->getYear(), computers[i]->getRAM(), computers[i]->getSpace());
//		}
//		this->_count = count;
//	}
//
//	CompStore& operator=(const CompStore& other) {
//		if (this != &other) {
//			setName(other._name);
//
//			for (size_t i = 0; i < this->_count; i++) {
//				delete this->_computers[i];
//			}
//			delete[] this->_computers;
//
//			this->_count = other._count;
//			this->_computers = new Computer * [this->_count];
//
//			for (size_t i = 0; i < this->_count; i++) {
//				this->_computers[i] = new Computer(other._computers[i]->getModel(), other._computers[i]->getColor(), other._computers[i]->getCPU(), other._computers[i]->getYear(), other._computers[i]->getRAM(), other._computers[i]->getSpace());
//			}
//		}
//		return *this;
//	}
//
//	void print() {
//		cout << "\tName: " << this->_name << endl;
//		cout << endl;
//		cout << "All Computers : " << endl;
//		for (size_t i = 0; i < this->_count; i++) {
//			this->_computers[i]->print();
//		}
//	}
//	void printComputersRAMGreaterThan(int minRAM) {
//		for (size_t i = 0; i < this->_count; i++) {
//			if (this->_computers[i]->getRAM() > minRAM)
//				this->_computers[i]->print();
//		}
//	}
//
//	void printComputersYearBetween(int minYear, int maxYear) {
//		for (size_t i = 0; i < this->_count; i++) {
//			if (this->_computers[i]->getYear() >= minYear && this->_computers[i]->getYear() <= maxYear)
//				this->_computers[i]->print();
//		}
//	}
//
//	Computer* getComputerById(int id) {
//		for (size_t i = 0; i < this->_count; i++) {
//			if (id == this->_computers[i]->getID()) {
//				return this->_computers[i];
//			}
//		}
//		return NULL;
//	}
//
//	Computer** getComputersByColor(const char* color) {
//		int len = 0;
//		for (int i = 0; i < this->_count; i++) {
//			if (strcmp(_computers[i]->getColor(), color) == 0)
//				len++;
//		}
//
//		if (len == 0)
//			return NULL;
//
//		Computer** computers = new Computer * [len + 1];
//		int len1 = 0;
//		for (size_t i = 0; i < this->_count; i++) {
//			if (strcmp(this->_computers[i]->getColor(), color) == 0) {
//				computers[len1] = this->_computers[i];
//				len1++;
//			}
//		}
//
//		return computers;
//	}
//
//	~CompStore() {
//		delete[] _name;
//		for (size_t i = 0; i < _count; i++)
//			delete _computers[i];
//		delete[] _computers;
//		_computers = NULL;
//	}
//};
//
//
//int main() {
//	Computer* comp1 = new Computer("Hp", "Black", "Intel Core i5-11200", 2019, 8, 512);
//	Computer* comp2 = new Computer("Asus", "Blue", "AMD Rizen", 2022, 32, 248);
//	Computer* comp3 = new Computer("Apple", "White", "Intel Core i9-12000", 2020, 64, 1000);
//
//
//
//
//	Computer** computers = new Computer * [3] {comp1, comp2, comp3};
//
//	CompStore compstore("Yasamal Mall", computers, 3);
//	compstore.print();
//
//
//}