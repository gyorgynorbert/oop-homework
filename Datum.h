#ifndef DATUM_H
#define DATUM_H

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

class Datum
{
private:
    int ev, honapp, nap;
public:
    Datum();
    Datum(int ev, int honapp, int nap);
    Datum(const Datum& d);

    void setEv(int ev){this-> ev = ev;};
    void setHonap(int honapp){this-> honapp = honapp;};
    void setNap(int nap){this-> nap = nap;};
    int getEv(){return ev;};
    int getHonap(){return honapp;};
    int getNap(){return nap;};

    bool operator==(Datum& jt);
    bool operator!=(Datum& jt);
    bool operator>(Datum& jt);
    bool operator<(Datum& jt);
    bool operator<=(Datum& jt);
    bool operator>=(Datum& jt);

    Datum operator++(int);
    Datum& operator++();
    Datum operator--(int);
    Datum& operator--();

    friend ostream& operator<<(ostream& os, const Datum& d);
    friend istream& operator>>(istream& is, Datum& d);

    string honap();
    bool szokoev();
    int maig();
    Datum currDate();
};

Datum::Datum()
{
    this->ev = 0;
    this->honapp = 0;
    this->nap = 1;
}

Datum::Datum(int ev, int honapp, int nap)
{
    this->ev = ev;
    this->honapp = honapp;
    this->nap = nap;
}

Datum::Datum(const Datum& d)
{
    this->ev = d.ev;
    this->honapp = d.honapp;
    this-> nap = d.nap;
}

string Datum::honap()
{
    switch(this->getHonap())
    {
    case 1:
        return "Januar";
    case 2:
        return "Februar";
    case 3:
        return "Marcius";
    case 4:
        return "Aprilis";
    case 5:
        return "Majus";
    case 6:
        return "Junius";
    case 7:
        return "Julius";
    case 8:
        return "Augusztus";
    case 9:
        return "Szeptember";
    case 10:
        return "Oktober";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "Nem helyes a honap!";
    }
}

bool Datum::szokoev()
{
    if (((ev % 4 == 0) && (ev % 100 != 0)) || (ev % 400 == 0))
        return true;
    return false;
}


bool Datum::operator==(Datum& jt)
{
    if(this->ev == jt.ev && this->honapp == jt.honapp && this->nap == jt.nap)
        return true;
    return false;
}

bool Datum::operator!=(Datum& jt)
{
    if(this->ev != jt.ev || this->honapp != jt.honapp || this->nap != jt.nap)
        return true;
    return false;
}

bool Datum::operator<(Datum& jt)
{
    if(this-> ev < jt.ev)
        return true;
    if(this-> honapp < jt.honapp)
        return true;
    if(this-> nap < jt.nap)
        return true;
    return false;
}

bool Datum::operator>(Datum& jt)
{
    if(this-> ev > jt.ev)
        return true;
    if(this-> honapp > jt.honapp)
        return true;
    if(this-> nap > jt.nap)
        return true;
    return false;
}

bool Datum::operator<=(Datum& jt)
{
    if(this-> ev <= jt.ev)
        return true;
    if(this-> honapp <= jt.honapp)
        return true;
    if(this-> nap <= jt.nap)
        return true;
    return false;
}

bool Datum::operator>=(Datum& jt)
{
    if(this-> ev >= jt.ev)
        return true;
    if(this-> honapp >= jt.honapp)
        return true;
    if(this-> nap >= jt.nap)
        return true;
    return false;
}

Datum Datum::operator++(int)
{
    if(this->getHonap() == 12 && this->getNap() == 31)
    {
        this->ev = ev + 1;
        this->honapp = 1;
        this->nap = 1;
        return *this;
    }
    else
    {
        if(this->szokoev()==true)
        {
            if(this->getHonap() == 2 && this->getNap() == 29)
            {
                this->honapp = honapp + 1;
                this-> nap = 1;
                return *this;
            }
            if((this->getHonap() == 1 || this->getHonap() == 3 || this->getHonap() == 5 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 10 || this->getHonap() == 12) && getNap() == 31)
            {
                this->honapp = honapp + 1;
                this->nap = 1;
                return *this;
            }
            if((this->getHonap() == 4 || this-> getHonap() == 2 || this->getHonap() == 6 || this->getHonap() == 9 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 11) && getNap() == 30)
            {
                this->honapp = honapp +1;
                this->nap = 1;
                return *this;
            }

            this->nap = nap + 1;
            return *this;
        }
        else
        {
            if(this->getHonap() == 2 && this->getNap() == 28 || this-> getNap() == 29)
            {
                this->honapp = honapp + 1;
                this-> nap = 1;
                return *this;
            }
            if((this->getHonap() == 1 || this->getHonap() == 3 || this->getHonap() == 5 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 10 || this->getHonap() == 12) && getNap() == 31)
            {
                this->honapp = honapp + 1;
                this->nap = 1;
                return *this;
            }
            if((this->getHonap() == 4 || this-> getHonap() == 2 || this->getHonap() == 6 || this->getHonap() == 9 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 11) && getNap() == 30)
            {
                this->honapp = honapp +1;
                this->nap = 1;
                return *this;
            }

            this->nap = nap + 1;
            return *this;
        }

    }
}

Datum& Datum::operator++()
{
    if(this->getHonap() == 12 && this->getNap() == 31)
    {
        this->ev = ev + 1;
        this->honapp = 1;
        this->nap = 1;
        return *this;
    }
    else
    {
        if(this->szokoev()==true)
        {
            if(this->getHonap() == 2 && this->getNap() == 29)
            {
                this->honapp = honapp + 1;
                this-> nap = 1;
                return *this;
            }
            if((this->getHonap() == 1 || this->getHonap() == 3 || this->getHonap() == 5 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 10 || this->getHonap() == 12) && getNap() == 31)
            {
                this->honapp = honapp + 1;
                this->nap = 1;
                return *this;
            }
            if((this->getHonap() == 4 || this-> getHonap() == 2 || this->getHonap() == 6 || this->getHonap() == 9 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 11) && getNap() == 30)
            {
                this->honapp = honapp +1;
                this->nap = 1;
                return *this;
            }

            this->nap = nap + 1;
            return *this;
        }
        else
        {
            if(this->getHonap() == 2 && this->getNap() == 28 || this-> getNap() == 29)
            {
                this->honapp = honapp + 1;
                this-> nap = 1;
                return *this;
            }
            if((this->getHonap() == 1 || this->getHonap() == 3 || this->getHonap() == 5 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 10 || this->getHonap() == 12) && getNap() == 31)
            {
                this->honapp = honapp + 1;
                this->nap = 1;
                return *this;
            }
            if((this->getHonap() == 4 || this-> getHonap() == 2 || this->getHonap() == 6 || this->getHonap() == 9 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 11) && getNap() == 30)
            {
                this->honapp = honapp +1;
                this->nap = 1;
                return *this;
            }

            this->nap = nap + 1;
            return *this;
        }

    }
}

Datum Datum::operator--(int)
{
    if(this->getHonap() == 1 && this->getNap() == 1)
    {
        this->ev = ev - 1;
        this->honapp = 12;
        this->nap = 31;
        return *this;
    }
    else
    {
        if(this->szokoev()==true)
        {
            if(this->getHonap() == 3 && this->getNap() == 1)
            {
                this->honapp = honapp - 1;
                this-> nap = 29;
                return *this;
            }
            if((this->getHonap() == 1 || this->getHonap() == 3 || this->getHonap() == 5 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 10 || this->getHonap() == 12) && getNap() == 1)
            {
                if(this->getHonap() == 8)
                    this->nap = 31;
                else
                    this->nap = 30;
                this->honapp = honapp - 1;
                return *this;
            }
            if((this->getHonap() == 4 || this-> getHonap() == 2 || this->getHonap() == 6 || this->getHonap() == 9 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 11) && getNap() == 1)
            {
                this->honapp = honapp - 1;
                this->nap = 31;
                return *this;
            }

            this->nap = nap - 1;
            return *this;
        }
        else
        {
            if(this->getHonap() == 3 && this->getNap() == 1)
            {
                this->honapp = honapp - 1;
                this-> nap = 28;
                return *this;
            }
            if((this->getHonap() == 1 || this->getHonap() == 3 || this->getHonap() == 5 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 10 || this->getHonap() == 12) && getNap() == 1)
            {
                if(this->getHonap() == 8)
                    this->nap = 31;
                else
                    this->nap = 30;
                this->honapp = honapp - 1;
                return *this;
            }
            if((this->getHonap() == 4 || this-> getHonap() == 2 || this->getHonap() == 6 || this->getHonap() == 9 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 11) && getNap() == 1)
            {
                this->honapp = honapp - 1;
                this->nap = 31;
                return *this;
            }

            this->nap = nap - 1;
            return *this;
        }

    }
}

Datum& Datum::operator--()
{
        if(this->getHonap() == 1 && this->getNap() == 1)
    {
        this->ev = ev - 1;
        this->honapp = 12;
        this->nap = 31;
        return *this;
    }
    else
    {
        if(this->szokoev()==true)
        {
            if(this->getHonap() == 3 && this->getNap() == 1)
            {
                this->honapp = honapp - 1;
                this-> nap = 29;
                return *this;
            }
            if((this->getHonap() == 1 || this->getHonap() == 3 || this->getHonap() == 5 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 10 || this->getHonap() == 12) && getNap() == 1)
            {
                if(this->getHonap() == 8)
                    this->nap = 31;
                else
                    this->nap = 30;
                this->honapp = honapp - 1;
                return *this;
            }
            if((this->getHonap() == 4 || this-> getHonap() == 2 || this->getHonap() == 6 || this->getHonap() == 9 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 11) && getNap() == 1)
            {
                this->honapp = honapp - 1;
                this->nap = 31;
                return *this;
            }

            this->nap = nap - 1;
            return *this;
        }
        else
        {
            if(this->getHonap() == 3 && this->getNap() == 1)
            {
                this->honapp = honapp - 1;
                this-> nap = 28;
                return *this;
            }
            if((this->getHonap() == 1 || this->getHonap() == 3 || this->getHonap() == 5 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 10 || this->getHonap() == 12) && getNap() == 1)
            {
                if(this->getHonap() == 8)
                    this->nap = 31;
                else
                    this->nap = 30;
                this->honapp = honapp - 1;
                return *this;
            }
            if((this->getHonap() == 4 || this-> getHonap() == 2 || this->getHonap() == 6 || this->getHonap() == 9 || this->getHonap() == 7 || this->getHonap() == 8 || this->getHonap() == 11) && getNap() == 1)
            {
                this->honapp = honapp - 1;
                this->nap = 31;
                return *this;
            }

            this->nap = nap - 1;
            return *this;
        }

    }
}

Datum Datum::currDate()
{
    time_t t = time(0);
    tm* now = localtime(&t);
    now->tm_year + 1900; now->tm_mon + 1; now->tm_mday;
    return Datum(now->tm_year+1900, now->tm_mon+1, now->tm_mday);
}
/*
int Datum::maig()
{
    unsigned int napok=0;

    Datum d(this->ev, this->honapp, this->nap);


    while(d.ev!=currDate.getEv() && d.honapp!=currDate().getHonap() && d.nap!=currDate().getNap())
    {
        napok++;
        d++;
    }
    return napok;
}
*/
ostream& operator<<(ostream& os, const Datum& d)
{
    os << d.ev << "." << d.honapp << "." << d.nap << endl;
    return os;
}

istream& operator>>(istream& is, Datum& d)
{
    char p;
    is >> d.ev >> p >> d.honapp >> p >> d.nap;
    return is;
}

#endif // DATUM_H
