#include<bits/stdc++.h>
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define inf INT_MAX
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int> > spq; 
struct AC{
};


const int N=5e5+10;

int n,m,a[N]; 
int main(){
	fst
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	
	cin>>n>>m;
	bool ff=1; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&(a[i]-a[i-1])!=(a[i-1]-a[i-2])) ff=0;
	}
	sort(a+1,a+n+1);
	if(n<=20){
		int ans=0;
		for(int state=0;state<(1<<n);state++){
			bool f=1;
			int mx=0,cnt=0,x=m;//mx记最大值，cnt记数量 
			for(int i=0;i<n;i++){
				if(state&(1<<i)){
					x-=(cnt*(a[i+1]-mx));
					if(x<0){
						f=0;
						break;
					}
					mx=a[i+1];
					
					cnt++;
				}
				
			
			}
			if(f){
				ans=max(ans,cnt);
			}	
			cnt=0;	
		}
		cout<<ans<<endl;
		
	}
	else if(ff){
		LL d=a[2]-a[1],ans=1,x=0;//x已消耗魔力数，ans石块，至少一块 
		while(m-x>ans*d){
			x+=ans*d;
			
		} 
		cout<<ans<<endl;
	}
	else cout<<1<<endl;

	
	return 0;
}
//CCF=chinese can fly 
/*
Oct31==Dec25?


*/
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
/*
		//\\                   ==========          ==
	   //  \\                ==          ==        == 
	  //    \\             ===             =       ==
	 //      \\           ===                      ==
	//        \\          ===                      ==
   //==========\\         ===                      ==
  //            \\         ===
 //              \\          ==          ==        ==
//                \\            ==========         ==




*/

