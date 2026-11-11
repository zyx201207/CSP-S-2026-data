#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,s,h=-1,iii;
	int x[200001]={};
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]>h){
			h=x[i];
			iii=i;
		}
	}
	x[iii]=-1;
	int th=0;
	while(1){
		if(th==s){
			cout<<h;
			break;
		}
		for(int i=1;i<=n;i++){
			if((x[i]&h)>h && x[i]!=-1){
				h=x[i]&h;
				x[i]=-1;
			}
		}
		th++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
