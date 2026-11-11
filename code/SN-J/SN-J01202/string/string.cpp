# include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,sum=0;
	cin>>n;
	n--;
	long long a;
	char b;
	string s,s1;
	bool d=true;
	cin>>a>>b;
	long long c=a;
	while(n--){
		if(a!=c){
			d=false;
		}
		s.append(a,b);
		s1+=b;
		cin>>a>>b;
	}
	if(a!=c){
		d=false;
	}
	s.append(a,b);
	s1+=b;
	if(d==true){
		s=s1;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			sum++;
		}
	}
	if(d==true){
		cout<<sum*a;
	}else{
		cout<<sum;
	}
	
	
	return 0;
}
