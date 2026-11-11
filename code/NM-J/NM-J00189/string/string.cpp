#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    int idx=0;
    cin>>n;
    vector<char> s;
    for(int i=0;i<n;i++){
    	int a;
    	char b;
    	cin>>a>>b;
    	while(a>0){
    		s.push_back(b);
    		a--;
		}
	}
	int len=s.size();
	int num=len/2;
	vector<char>t1;
	vector<char>t2;
	for(int i=0;i<num;i++){
		t1.push_back(s[i]);
	}
	for(int i=len-1;i>=len-num;i--){
		t2.push_back(s[i]);
	}
	int ans=0;
	for(int i=0;i<num;i++){
		if(t1[i]!=t2[i]){
			ans++;
		}
	}
	cout<<ans;
    return 0;
}
