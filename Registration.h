#pragma once

class Exception:public exception
{
private:
	string _text;
	string _date;
	string _time;
	string _source;
	int _line;

public:
	Exception(string text = "Null Exeption", string date = "NULL", string time = "NULL", string source = "NUll", int line = 0)
		:exception(text.c_str())
	{
		_date = date;
		_time = time;
		_source = source;
		_line = line;

		_text = "Text:" + string(exception::what())
			+ "\nFile: " + _source
			+ "\nDate: " + _date
			+ "\nTime: " + _time
			+ "\nLine: " + to_string(_line);
	}

	string GetText() const { return _text; }
	string GetDate() const { return _date; }
	string GetTime() const { return _time; }
	string GetSource() const { return _source; }
	int GetLine() const { return _line; }



	char const* what() const override
	{
		return _text.c_str();
	}

};
class DataBaseException :public Exception 
{
private:
	string _message;
	string _data;
	string _time;

public:
	DataBaseException(string message = "NULL", string data = "Null Data", string time = "Null Time")
		:Exception(message.c_str())
	{
		_data = data;
		_time = time;

		_message = "Messege: " + string(Exception::what())
			+ "Data: " + _data
			+ "Time: " + _time;
	}

	char const* what() const override
	{
		return _message.c_str();
	}

};

class InvalidArgumentEXception : public Exception 
{

private:
	string message;
	int _line;
	string _file;

public:
	InvalidArgumentEXception(string message = "Null", string file = "Null File", int line = 0)
		:Exception(message.c_str())
	{
		_line = line;
		_file = file;
		message = "Message: " + string(Exception::what())
			+ "FILE: " + _file
			+ "Line: " + to_string(_line);
	}


	char const* what() const override
	{
		return message.c_str();
	}

};

class User
{
protected:
	int id;
	
	string password;
	string name;
	string surname;

public:
	string username;

	User() = default;
	User(int id,string username,string password,string name,string surname)
		:id(id),username(username),password(password),name(name),surname(surname){}


	void SetId(int id)
	{
		if (id < 3)
		{
			this->id = id;
		}
		throw("3 herifden kicikdir");
	}
	

	int GetId() { return id; }
	string GetUsername() { return username; }
	string GetPassword() { return password; }
	string GetName() { return name; }
	string GetSurname() { return surname; }

	void show() const
	{
		cout << "Id: " << id << endl;
		cout << "Username: " << username << endl;
		cout << "Password: " << password << endl;
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
	}
};



class DataBase
{
private:
	User** users;
	int user_count = 0;


public:
	DataBase()
	{
		users = new User * [100];
	}


	void SetUserCount(int user_count)
	{
		if (user_count != 0)
		{
			this->user_count = user_count;
		}
		throw("0 ola bilmez");
	}

	int GetUserCount() { return user_count; }

	void addUser(const User& user)
	{
		users[user_count] = new User(user);
		user_count++;
	}

	User& getUserByUsername(string username)
	{
		for (size_t i = 0; i < user_count; i++)
		{
			if (users[i]->username == username)
				return *users[i];
		}
	}


	void upDateUser(User& olduser, const User& newUser)
	{
		olduser = newUser;
	}

	~DataBase()
	{
		delete[] users;
	}


};

class Registration
{
	DataBase _database;

public:

	Registration(const DataBase& database) {
		_database = database;
	}

	void signIn(string username, string password)
	{
		User& user = _database.getUserByUsername(username);

		if (user.GetUsername().empty())
		{
			throw Exception("Null Error oldu->", __FILE__, __DATE__, __TIME__, __LINE__);
		}
		if (user.GetPassword() != password)
		{
			throw Exception("Null Error oldu->", __FILE__, __DATE__, __TIME__, __LINE__);
		}
	}

	void signUp(string username, string password, string name, string surname)
	{
		User& user = _database.getUserByUsername(username);
		if (!user.GetUsername().empty())
		{
			throw DataBaseException("Error in DataBase", __DATE__, __TIME__);
		}

		if (username.length() < 6)
		{
			throw InvalidArgumentEXception("User 6 dan kicik", __FILE__, __LINE__);
		}
		if (!isupper(username[0]))
		{
			throw InvalidArgumentEXception("Baslangic Boyuk herf ile", __FILE__, __LINE__);
		}
		if (password.length() < 6)
		{
			throw InvalidArgumentEXception("Password 6 herifden kiicikdir", __FILE__, __LINE__);
		}
		if (name.length() < 3)
		{
			throw InvalidArgumentEXception("Ad 3 herifden kicik ola bilmez", __FILE__, __LINE__);
		}
		if (surname.length() < 4)
		{
			throw InvalidArgumentEXception("Soy ad 4 herifden kicik ola bilmez", __FILE__, __LINE__);
		}
	}


};


class StartUp
{
public:
	void Start()
	{
		try
		{
			DataBase database;
			Registration registration(database);

			User user1(1, "ZehraMm", "Zehra222", "Zehra", "Memmedzade");
			database.addUser(user1);

			registration.signIn("NazzHesenov", "Naz3221");

			registration.signUp("NurayIsov2", "Nuray333", "Nuray", "Ismayilov");

		}
		catch (Exception e)
		{
			cout << "Exception ->" << e.GetText() << endl;
		}
		catch (DataBaseException d)
		{
			cout << "DataBase Exception" << d.GetText() << endl;
		}

	}
};