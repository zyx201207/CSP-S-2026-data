#include<bits/stdc++.h>
using namespace std;
int ans;
int n;
class C {
public:
    int start;
    int end;
    char c;
    C() {
        start = 0;
        end = 0;
        c = 0;
    }
    inline int len(const int& c) {
        return end - start + 1;
    }
};
C a[200001];
bool b[200001];
void f1(int& c, const int& num = 0, char, const int& x), f2(int& c, const int& num = 0, char, const int& x);

void f1(int& c, int num = 0, char cc = 0, const int& x) {
    if (x > n || num == 0){
        return;
    }
    if (a[n - c + 1].c != cc) {
            ans += min(a[n - c + 1].len(), num);
    }
    if (a[n - c + 1].len() >= num) {
        f2(++c, a[n - c + 2].len() - num, a[n - c + 2].c, x + a[n - c + 2].len());
    } else {
        f1(++c, num - a[n - c + 2].len(), cc, x + num);
    }
}
void f1(int& c, int num = 0, char cc = 0, const int& x) {
    if (x > n || num == 0){
        return;
    }

    if (a[n].c != cc) {
            ans += min(a[n].len(), num);
    }
    if (a[n].len() <= num) {
        f2(++c, a[n].len() - num, a[n].c, x + a[n].len());
    } else {
        f1(++c, num - a[n - c + 2].len(), cc, x + num);
    }
}
inline void f(int& c, int& x) {
    num = abs(a[n].len()-a[c].len());
    if(a[n].len() > a[n].len){
    if (a[n].c != cc) {
            ans += min(a[n].len(), num);
    }
    if (a[n].len() <= num) {
        f2(++c, a[n].len() - num, a[n].c, x + a[n].len());
    } else {
        f1(++c, num - a[n - c + 2].len(), cc, x + num);
    }}
    if(a[n].len() <= a[n].len){
    if (a[n - c + 1].c != cc) {
            ans += min(a[n - c + 1].len(), num);
    }
    if (a[n - c + 1].len() >= num) {
        f2(++c, a[n - c + 2].len() - num, a[n - c + 2].c, x + a[n - c + 2].len());
    } else {
        f1(++c, num - a[n - c + 2].len(), cc, x + num);
    }}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d\n", &n);
	if(n == 1) {
        printf("0\n");
        return 0;
	}
	for (int i = 1; i <= n; i++){
        int num;
        scanf("%d %c\n", &num, &a[i].c);
        a[i].start = a[i - 1].end + 1;
        a[i].end = a[i].start + num - 1;
        b[i] = a[i].c == a[i - 1].c;
	}
	int c = 1, int x = 1;
	while (a[c].end < a[n].end / 2) {
        f(c, x);
	}
	printf("%d\n", ans);
	return 0;
}
