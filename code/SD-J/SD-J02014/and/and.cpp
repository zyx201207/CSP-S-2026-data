#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[200005];
int n,m;

bool check(){
	int pow=1;
	
	for(int i=1;i<=30;i++){
		pow = (i==1?1:pow*pow);
	}
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	
	cin>>n>>m;
	
	int mx=-67;
	int alland=a[1];
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		mx = max(mx,a[i]);
		
		if(i>=2){
			alland = alland&a[i];
		}
	}
	
	if(m==1){//5pts
		cout<<mx<<"\n";
		
		exit(0);
	}
	else if(m==n){ //5pts
		cout<<alland<<"\n";
	}
	else if(m==2){ //15pts
		int mx=-6767;
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx = max(mx,(a[i]&a[j]));
			}
		}
		
		cout<<mx<<"\n";
	}
	else if(check()){ //13,5pts
		sort(a+1,a+n+1);
		
		cout<<a[n-m+1]<<"\n";
	}
	else{
		int mx=-6767;
		
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			bool flag=1;
			int ad;
			
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					++cnt;
					
					if(flag){
						ad = a[j+1];
						
						flag = 0;
					}
					else{
						ad = ad&a[j+1];
					}
				}
			}
			
			if(cnt==m){
				mx = max(mx,ad);
			}
		}
		
		cout<<mx<<"\n";
		
		return 0;
	}
	
	return 0;
}

//我完蛋了

/*
T3 1~5 暴力
6 //ok
7 //ok
8~10 双重循环 //ok
13 //ok
55pts
*/ 
