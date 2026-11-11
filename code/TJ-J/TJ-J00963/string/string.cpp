#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],m,ans,sum1,sum2;
stack<long long> a1;
stack<char> s1; 
stack<long long> a2;
stack<char> s2;
char s[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		a1.push(a[i]);s1.push(s[i]);
		sum1+=a[i];
	}
	for(int i=n;i>=1;i--){
		a2.push(a[i]);s2.push(s[i]);
	}
	while(!s1.empty()&&!s2.empty()&&sum2<(sum1/2)){
		if(s1.top()==s2.top()){
			if(a1.top()>a2.top()){
				sum2+=a2.top();
				m=a1.top()-a2.top();
				a2.pop();s2.pop();
				a1.pop();a1.push(m);
				m=0;
			}else if(a1.top()<a2.top()){
				sum2+=a1.top();
				m=a2.top()-a1.top();
				a1.pop();s1.pop();
				a2.pop();a2.push(m);
				m=0;
			}else if(a1.top()==a2.top()){
				sum2+=a1.top();
				a1.pop();s1.pop();
				a2.pop();s2.pop();
				m=0;
			}
		}else{
			if(a1.top()>a2.top()){
				ans+=a2.top();
				sum2+=a2.top();
				m=a1.top()-a2.top();
				a2.pop();s2.pop();
				a1.pop();a1.push(m);
				m=0;
			}else{
				sum2+=a1.top();
				ans+=a1.top();
				m=a2.top()-a1.top();
				a1.pop();s1.pop();
				a2.pop();a2.push(m);
				m=0;
			}
		}
	}
	cout<<ans;
	return 0;
}


