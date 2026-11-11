#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n,avr,ans=0;
	cin>>m>>n;
	int c[n+10];
	for (int i=0;i<n;i++){
		cin>>c[i+1];
		avr=(c[i+1+c[i+2])/2;
	}
	for(int j=0;j<n;j++){
		if(c[j+1]>avr&&m>avr)
			m=m-avr;
		if(c[j+1]>avr&&m<avr){
			m=avr-m;
			ans+=1;
		}
		if(m<=0)
			break;
		}
	cout<<ans;
	fclose("crystal.in")
	fclose("crystal.out");
	return 0;
	}
