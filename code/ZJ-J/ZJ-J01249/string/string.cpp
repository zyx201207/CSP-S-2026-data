#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,c1[100005],j1=1,j2,p1,p2,k,x=0,h=0;
	string c2[100005];
	cin>>a;
	j2=a;
	for(int i=1;i<=a;i++){
		cin>>c1[i]>>c2[i];
	}
	p1=c1[1];
	p2=c1[a];
	while(1){
		if(p1>=p2){
			k=1;
		}
		else{
			k=0;
		}
		if(c2[j1] != c2[j2]){
			h+=min(p1,p2)-x;
		}
		x=min(p1,p2);
		if(k){
			j2--;
			p2+=c1[j2];
		}
		else{
			j1++;
			p1+=c1[j1];
		}
		if(j1>a || j2<1){
			break;
		}
	}
	cout<<h/2;
	return 0;
}
