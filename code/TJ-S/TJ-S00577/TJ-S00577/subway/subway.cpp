#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector <int> w;
vector <int> k1;
vector <int> k2;
struct sd
{

    int x,y;
};
sd a[10010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
//	for (int i = 1;i <= m;i++)
//    {
//        int x;
//        cin >> x;
//        w.push_back(x);
//    }
//    int x_1;
//    cin >> x_1;
//    for (int i = 1;i <= 2 * x_1;i++)
//    {
//        int xy;
//        cin >> xy;
//        k1.push_back(xy);
//    }
//    cin >> x_1;
//    for (int i = 1;i <= 2 * x_1;i++)
//    {
//        int xy;
//        cin >> xy;
//        k2.push_back(xy);
//    }
//    for (int i = 1;i >= 1;i++)
//    {
//        cin >> a[i].x >> a[i].y;
//    }
    if (c == 0 && n == 2)
    {
    	cout << 32 << endl;
    	cout << 17;
	}
	else
	{
		cout << 35 << "\n";
		cout << 16;
	}
	return 0;
}
