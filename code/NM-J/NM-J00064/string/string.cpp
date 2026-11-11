#include<bits\stdc++.h>
using namespace std;
int  n;
long long a,t;
char c;
string s;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		cin>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}

	if(s.size()%2==0){
		for(int i=1;i<=s.size()/2;i++){
			if(s[i]!=s[i+s.size()/2]){
			t++;	
			}
		}
	}else{
		for(int i=1;i<=(s.size()-1)/2;i++){
			if(s[i]!=s[i+s.size()/2]){
			t++;	
			}
		}
	}
	cout<<t;
	return 0;
}
