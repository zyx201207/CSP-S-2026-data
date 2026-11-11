#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
int a[N],s,ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	s/=2;
	int x=0,y=0,i,j;
	for(i=1,j=n;;){

		if(x+a[i]>s){
			break;
		}
		x+=a[i];
		
		while(x>=y+a[j]){
			if(c[i]!=c[j]){
//				cout<<i<<" "<<j<<endl;
				ans+=a[j];
			}
			y+=a[j];
			j--;
			
		}
		int q=x-y;
		if(c[i]!=c[j]){
			ans+=q;
		}
		y=x;
		a[j]-=q;
		 i++;
	}
	x=s;
	while(x>=y+a[j]){
		if(c[i]!=c[j]){
			ans+=a[j];
		}
		y+=a[j];
		j--;
	}
	cout<<ans;
	return 0;
}
/* 6
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
1000000000 b*/