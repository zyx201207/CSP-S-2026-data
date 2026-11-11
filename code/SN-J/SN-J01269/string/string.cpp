#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,a[200006];
char c[200006];
signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" ,"w" , stdout);
	
	cin>>n;
	int L=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i]; 
	}
	int l=0,r=n+1;
	int sl=0,sr=0;
	int ls=0,rs=0;
	char nowl='$',nowr='#'; 
	int ans=0;
	while(1){
		
		if(r==l+1){
			break;
		}
		if(sl<=sr){//×ó±ß±ÈÓÒ±ßÉÙ 
			l++;
			sl+=a[l];
			ls+=a[l];
			nowl=c[l];
			int alls=ls;
			int alrs=rs;
			if(nowl==nowr){
				ls -= min(alls,alrs);
				rs -= min(alls,alrs);
				continue;
			}
			ans+=min(alls,alrs);
			ls-=min(alls,alrs);
			rs-=min(alls,alrs);
			
		}
		else{
			r--;
			sr+=a[r];
			rs+=a[r];
			nowr=c[r];
			int alls=ls;
			int alrs=rs;
			if(nowl==nowr){
				ls -= min(alls,alrs);
				rs -= min(alls,alrs);
				continue;
			}
			ans+=min(alls,alrs);
			ls-=min(alls,alrs);
			rs-=min(alls,alrs);
			
		}
	} 
	cout<<ans;
} 
