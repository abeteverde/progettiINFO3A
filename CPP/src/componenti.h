//componenti.h

#include <string>

//classe del protagonista
class Protagonista {
private:
	std::string nick;
	float vita;		//quando a 0 finisce il gioco
	//questi servono per combattere i diversi nemici
	float velocita;
	float forza;
	float magia;
public:
	Protagonista(std::string n, float v, float s, float f, float m);
	~Protagonista();

	float getForza() const;
	void setForza(float forza);
	float getMagia() const;
	void setMagia(float magia);
	std::string getNick();
	void setNick(const std::string &nick);
	float getVelocita() const;
	void setVelocita(float velocita);
	float getVita() const;
	void setVita(float vita);
	std::string toString();
};


//classe nemico
class Nemico {
protected:	//ereditate dai figli
	float reward;
public:
	Nemico(float r);
	virtual ~Nemico(); //virtual per poter chiamare il distruttore dei figli in caso vengano distrutti tramite referenza al padre

	virtual bool combatti(Protagonista &p);	//will be overridden
	virtual std::string toString();
	float getReward() const;
	void setReward(float reward);
};

class Drago : virtual public Nemico {
protected:
	float forza;
public:
	Drago(float r, float f);
	virtual ~Drago();

	virtual bool combatti(Protagonista &p);
	virtual std::string toString();
	float getForza() const;
	void setForza(float forza);
};

class Mago: virtual public Nemico {
protected:
	float magia;
public:
	Mago(float r, float m);
	virtual ~Mago();

	virtual bool combatti(Protagonista &p);
	virtual std::string toString();
	float getMagia() const;
	void setMagia(float magia);
};

class DragoMagico : public Drago, public Mago {
public:
	DragoMagico(float r, float f, float m);
	virtual ~DragoMagico();
	virtual bool combatti(Protagonista &p);
	virtual std::string toString();
};

class Elfo : virtual public Nemico {
protected:
	float velocita;
public:
	Elfo(float r, float v);
	virtual ~Elfo();

	virtual bool combatti(Protagonista &p);
	virtual std::string toString();
	float getVelocita() const;
	void setVelocita(float velocita);
};
