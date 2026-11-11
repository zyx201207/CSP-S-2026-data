#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<int>num(n+1,0);
	vector<char>zm(n+1,' ');
	long long he=0;
	for(int i=0;i<n;i++){
		int x;
		char h;
		cin>>x>>h;
		zm[i]=h;
		he+=x;
		num[i]=x;
	}
	long long mid;
	if(he/2==0){
		mid=he/2;
	}else{
		mid=he/2;
	}
	long long goo=0;
	long long goor=0;
	int zx=0;
	int yx=0;
	long long ans=0;
	while(goo<mid && goor<mid){
		goo+=num[zx];
		char l=zm[zx];
		
		while(goor<goo){
			if(goor+num[n-1-yx]<=goo){
				goor+=num[n-1-yx];
				if(zm[zx]!=zm[n-1-yx]){
					ans+=num[n-1-yx];
				}
				yx++;	
			}else{
				
				if(zm[zx]!=zm[n-1-yx]){
					ans+=goo-goor;
					
				}
				num[n-1-yx]=goor+num[n-1-yx]-goo;
				goor=goo;
			}
			
		}
		zx++;
		
		
	}
	cout<<ans<<endl;


}
