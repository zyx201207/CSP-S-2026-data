#include<bits/stdc++.h>
using namespace std;
int n,m,j=1;
long long a[5010],x,b[5010];
string s;
int c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	while(cin>>x){
		for(int i=j;i<=n;i++){
			a[i]=x;
			s=s+char(a[i]+'0');
			c=s.find(char(a[i]+'0'));
			if(c==i){
				s.erase(c,5005);
			}
			j++;
		}
		for(int i=0;i<s.size();i++){
			b[s[i]]++;
		}
	}
	for(int i=0;i<=5002;i++){
		if(b[i]!=0){
			cout<<b[i]<<" ";
		}
	}
	return 0;
}
