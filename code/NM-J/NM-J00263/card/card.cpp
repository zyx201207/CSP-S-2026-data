#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

int n, m, ans[N], an, deskn;
vector<int> a;
vector<int> desk;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin >> n >> m;
    an = n;
    deskn = 0;
    desk.push_back(0);
    a.push_back(0);
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

//    for (int i = 1; i <= n; i++) {
//        int length = a.size();
//        for (int j = i; j <= length; j++) {
//            desk.push_back(a[j]);
//            a.erase(a.begin() + j, a.begin() + j);
//            deskn++;an--;
//            for (int w = 1; w <= j; w++) {
//                if (desk[w] == a[j]) {
//                    for (int temp = w; temp < j; temp++) a.push_back(desk[temp]);
//                    desk.erase(desk.begin() + w, desk.begin() + w + j);
//                    break;
//                }
//            }
//            for (int temp = 1; temp <= desk.size(); temp++) {
//                cout << desk[temp] << ' ';
//            } cout << endl;
//            for (int temp = 1; temp <= a.size(); temp++) {
//                cout << a[temp] << ' ';
//            } cout << endl << endl;
//        }
//    }
	return 0;
}
