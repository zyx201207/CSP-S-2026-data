#include <bits/stdc++.h>
#define debug puts("OK")

using namespace std;

const int maxn = 2e5 + 10;

int n, m;
long long total_len;

long long ans;

struct range
{
	int pos;
	long long len;
	char type;
	range (int _ = 0, long long __ = 0, char ___ = 0) : pos(_), len(__), type(___) {}
	void print ()
	{
		cout << "range:" << pos << ' ' << len << ' ' << type << endl;
	}
};

vector <range> rg(1);

struct scanner
{
	int type; // 1 -> l to r, -1 -> r to l
	int range_pos;
	long long real_pos;
	long long remain;
	scanner (int _, int __, long long ___) : type(_), range_pos(__), real_pos(___) {remain = rg[range_pos].len;}
	void next_range ()
	{
		real_pos += type * rg[range_pos].len;
		range_pos += type;
		remain = rg[range_pos].len;
	}
	void move_in_range (int step)
	{
	    real_pos += type * step;
	    remain -= step;
	}
	void print ()
	{
	    cout << "Scanner:" << endl;
	    cout << type << ' ' << range_pos << ' ' << real_pos << ' ' << remain << endl;
	    rg[range_pos].print();
	    puts("");
	}
};


int main ()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int a;
		char c;
		scanf("%d %c", &a, &c);
		total_len += a;

		if (c == rg[m].type) rg[m].len += a; // merge this range
		else rg.push_back(range(++m, a, c)); // create new ranges
	}

	scanner l(1, 1, 1), r(-1, m, total_len);

    while (l.real_pos < r.real_pos)
    {
        long long llen = l.remain;
        long long rlen = r.remain;
        char ltype = rg[l.range_pos].type;
        char rtype = rg[r.range_pos].type;

        if (ltype != rtype) // different
        {
        	//debug;
            ans += min(llen, rlen);
        }

        if (llen < rlen)
        {
            l.next_range();
            r.move_in_range(llen);
        }
        else if (llen == rlen)
        {
            l.next_range();
            r.next_range();
        }
        else
        {
        	r.next_range();
            l.move_in_range(rlen);
        }
    }
	cout << ans;
	return 0;
}
/*
3
2 a
2 b
1 c
main mind:
scan from both two sides,
add min(left_now_range_len, right_now_range_len) cost if (left_now_range_type != right_now_range_type),
than change the shortest side's index to next (left: +1, right: -1) and update the len and the type,
repeat this process until meet in the middle.
*/
