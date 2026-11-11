#include<bits/stdc++.h>
using namespace std;
int a[500001],c,d,n,m,e,f;
bool b[500001];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0)	c=a[i];
		else if(c!=a[i])	d=a[i];
	}
	if(m==1)	cout<<n;
	else if(m==2){
		for(int i=0;i<n;i++){
			s+=a[i];
			for(int j=0;j<i;j++)	if(s[j]==a[i]){
				s="";
				for(int l=0;l<j;l++)	s+=l;
				s+=a[i];
			}
		if(s.size()==1){
			if(s[0]==c)	e++;
			else	f++;
		}
		else	e++,f++;
		}
		cout<<e<<' '<<f;
	}
	else	for(int i=0;i<n;i++)	cout<<1;
	return 0;
}
