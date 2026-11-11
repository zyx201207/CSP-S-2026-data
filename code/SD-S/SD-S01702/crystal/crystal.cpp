#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#define ll long long
#define forr(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const ll MaxN=5e5+55;
ll n,m,a[MaxN],b[MaxN],flag=false;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	forr(i,1,n){
		cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[1]=0;
    forr(i,2,n){
		b[i]=(a[i]-a[i-1])+b[i-1];
    } 
    sort(b+1,b+n+1);
	forr(i,1,n){
		if(b[i]>m){
			cout<<(i-1)<<endl;
			flag=true;
			break;
		}
	}
	if(!flag)    cout<<n<<endl;
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
