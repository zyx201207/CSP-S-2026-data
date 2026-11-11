#include<bits/stdc++.h>
using namespace std;
int sum[100001],s,t=1,sut,num=0;
int main(){
	int a[100001];
	string c[10001];
    cin>>s;
    for(int i=1;i<=s;i++){
    	cin>>a[i]>>c[i];
    	sut+=a[i];
	}
    for(int i=1;i<=s;i++){
    	for(int j=1;j<=a[i];j++){
    		sum[t]=c[i];
    		t++;
		}
	}
	for(int i=0;i<=sut/2-1;i++){
		if(sum[i]!=sum[sut-i]){
			num++;
		}
	}
	cout<<num;
    return 0;
}
