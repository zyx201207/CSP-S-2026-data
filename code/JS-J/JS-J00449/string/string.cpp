#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>n;
	//1.pin jie                                                                                                                                                                                        
	for(int i=1;i<=n;i++){
		int num;
		string ss;
		cin>>num>>ss;
		while(num--){
			s+=ss;
		}
	}
    //2.fan zhuan                                                                                                                                                                                      
	string ns=s;
	reverse(ns.begin(),ns.end());
	//3.bi jiao                                                                                                                                                                                        
	long long len=s.size();
	long long mid=len/2;
	for(int i=0;i<mid;i++){
		if(s[i]!=ns[i])ans++;
	}
    cout<<ans;
	return 0;
}
