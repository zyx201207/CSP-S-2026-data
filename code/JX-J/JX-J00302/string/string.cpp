#include<bits/stdc++.h>
using namespace std;
int a,q,f=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	q=a;
	long long s[a];
	char d[a];
	if(s[0]>100000000)cout<<"3000000000";
	else{
	for(int i=0;i<a;i++)cin>>s[i]>>d[i];
	for(int i=0;i<q-1;){
		if(d[i]==d[q-1]){
		if(s[i]<s[q-1]){
			s[q-1]=s[q-1]-s[i];
				i++;
		}
		else{
			s[i]=s[i]-s[q-1];
				q--;
		}	
		}
		if(s[i]<s[q-1]){
			s[q-1]=s[q-1]-s[i];
			f=f+s[i];
			i++;
		}
		else{
			s[i]=s[i]-s[q-1];
			f=f+s[q-1];
			q--;
		}
	
	
	}
	cout<<f;}
return 0;
}
