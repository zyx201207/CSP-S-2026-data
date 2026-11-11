#include<bits/stdc++.h>	

using namespace std;
int n;
string sz[5000000],sz1[5000000],sz2[5000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a,ant=1,sum=0;
	string b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			sz[ant]=b;
			ant++;
		}
	}
	ant-=1;
	int xb=1;
	if(ant%2==1){
		for(int i=1;i<=ant/2;i++){
			sz1[i]=sz[i];
		}
		for(int i=(ant/2)+2;i<=ant;i++){
			sz2[xb]=sz[i];
			xb++;
		}
		for(int i=1;i<=ant;i++){
			if(sz1[i]!=sz2[i]){
				sum++;
			}
		}
	}
	else{
		for(int i=1;i<=ant/2;i++){
			sz1[i]=sz[i];
		}
		for(int i=ant/2;i<ant;i++){
			sz2[xb]=sz[i];
			xb++;
		}
		for(int i=1;i<=ant;i++){
			if(sz1[i]!=sz2[i]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
