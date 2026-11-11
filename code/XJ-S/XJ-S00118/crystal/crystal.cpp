#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+20;
long long int n;
long long int a[N];
long long int maxx=-1e9;
long long int len;
long long int p=0;
long long int len2;
string s;
bool check(long long int q){
	//´óÓÚm·µ»Øtrue
	long long int len1=0;
	stack<int> st;
	while(q>=10){
		int l=q%10;
		q=q/10;
		st.push(l);
		len1++;
	}
	st.push(q);
	len1++; 
	if(len1>len2){
		return true;
	}
	long long int k=0;
	if(len1==len2){
		while(!st.empty()&&st.top()==s[k]-'0'){
			k++;
			st.pop();
		}
		if(!st.empty()&&st.top()>s[k]-'0'){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>s;
	len2=s.size();
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++){
		long long int k=a[i+1]-a[i];
		p+=len*k;
		if(check(p)){
			len=0;
			p=0;
		}
		else{
			len++;
		}
		maxx=max(maxx,len+1);
	}
	cout<<maxx<<endl;
	return 0;
} 

