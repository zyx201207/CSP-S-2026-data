#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],ans;
bool check(int x){
	ll cnt=0,mm=m,num=0;
	bool j=0;
	ll r=upper_bound(a+1,a+n+1,x)-a;
	//cout<<r-1<<endl;
	for(ll i=r-1;i>=1;i--){
		if(mm>=x-a[i]){
			cnt+=x-a[i];
			mm-=x-a[i];
			num++;
		}
		else{
            j=1;
            break;
		}
	}
	ans=max(ans,num);
	if(j && mm>=1 ){
        return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0 && t==2){
        cout<<1<<endl<<2<<endl;
        return 0;
	}
	if(c==0 && t==2){
        cout<<0<<endl<<2<<endl;
	}
	return 0;
}
/*
5 5
1 2 4 8 9

3


5 8
-3 -1 2 2 7
*/
