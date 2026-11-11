#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli unsigned lli
#define f(i, a, b) for(lli i = a; i <= b; i++)

const ulli MAX_SIZE = 1e5 + 5;

struct Ticket
{
	string id, pos;	
};

bool isSameId(Ticket a, Ticket b)
{
	return a.id == b.id;
}

bool isSameCol(Ticket a, Ticket b)
{
	string col_a = a.pos.substr(0, 2), col_b = b.pos.substr(0, 2);
	
	return isSameId(a, b) && (col_a == col_b);
}

bool isSameSide(Ticket a, Ticket b)
{
	char row_a = a.pos[a.pos.size()-1], row_b = b.pos[b.pos.size()-1];
	
	if(row_a <= 'C')
	{
		return isSameCol(a, b) && (row_b <= 'C');
	}
	else
	{
		return isSameCol(a, b) && (row_b >= 'D');
	}
}

bool isNext(Ticket a, Ticket b)
{
	char row_a = a.pos[a.pos.size()-1], row_b = b.pos[b.pos.size()-1];
	
	return isSameSide(a, b) && (abs(row_a-row_b) == 1);
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	Ticket r, x;
	
	cin >> r.id >> r.pos >> x.id >> x.pos;
	
	cout << isSameId(r, x) << isSameCol(r, x) << isSameSide(r, x) << isNext(r, x) << "\n";
	
	return 0;
}
