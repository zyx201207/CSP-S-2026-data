#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool used[200005];
int a[200005];
int maxx = 0,n,m;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int deep,int now){
	if(deep == m+1){
		maxx = max(maxx,now);
		return;
	}
	int na;
	for(int i = 0;i<n;i++){
        if(deep == 1){
            na = a[i];
        }
        else{
            na = a[i]&now;
        }
		if(!used[i] && na >= maxx){
			used[i] = true;
			dfs(deep+1,na);
			used[i] = false;
		}
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	if(m == 1){
		cout << a[0];
		return 0;
	}
	if(m == n){
		for(int i = 1;i<n;i++){
			a[0] &= a[i];
		}
		cout << a[0];
		return 0;
	}
	dfs(1,0);
	cout << maxx;
	return 0;
}

