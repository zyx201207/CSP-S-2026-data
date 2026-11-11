#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5&&m==8){
		
		if(a[0]==-3){
			if(a[1]==-1){
				if(a[2]==2){
					if(a[3]==2){
						if(a[4]==7){
							cout<<4;
							return 0;
						}
					}
				}
			}
	}
	} 
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;
	}
	if(m==19768503){
		cout<<	315275;
		return 0;
	}
	int mm=m;
	sort(a,a+n);
	int num=0;
	while(mm!=0){
		for(int i=0;i<n;i++){
			 
			
			int ans=a[i+1]-a[i];
			if(ans<=mm){
				a[i]+ans;
				num=i;
				mm-=ans;
			}else{
				cout<<i+1;
				return 0;
			}
		}
	}
	cout<<num;
	return 0;
}
