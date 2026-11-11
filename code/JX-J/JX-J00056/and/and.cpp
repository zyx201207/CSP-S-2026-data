#include <bits/stdc++.h>
using namespace std;
int n,m,as=(1<<31)-1,a[200001];
bool cmp(int x,int y){
    return x>y;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++)
        cin >>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++){
        as&=a[i];
    }
    cout <<as;
	return 0;
}
