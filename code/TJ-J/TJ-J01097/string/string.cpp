#include<bits/stdc++.h>
using namespace std;
vector<char> hui(vector<char> s){
	sort(s.begin(),s.end());
	int num=0;
	char ji=0;
	char c=s[0];
	vector<char> v;
	vector<int> n;
	vector<char> h;
	for(int i=0;i<s.size();i++){
		if(s[i]==c){
			num++;
		}else{
			v.push_back(c);
			c=s[i];
			n.push_back(num);
			num=0;
		}
	}for(int i=0;i<v.size();i++){
		if(n[i]%2==0){
			int x=n[i]/2;
			char lin=v[i];
			h.push_back(lin*x);
		}else{
			ji=v[i];
			int x=(n[i]-1)/2;
			char lin=v[i];
			h.push_back(lin*x);
		}
	}vector<char> re=h;
	reverse(h.begin(),h.end());
	re.push_back(ji);
	for(int i=0;i<h.size();i++){
		re.push_back(h[i]);
	}
	return h;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	char s;
	int x;
	int num=0;
	vector<char> c;
	for(int i=0;i<a;i++){
		cin>>x>>s;
		c.push_back(s*x);
	}
	vector<char> b_c=c;
	c=hui(c);
	for(int i=0;i<c.size();i++){
		if(c[i] != b_c[i]){
			num++;
		}
	}
	if(c==b_c){
		cout<<0;
		return 0;
	}
	else if(num%2){
		cout<<(num+1)/2;
	}else{
		cout<<num/2;
	}
	return 0;
}
