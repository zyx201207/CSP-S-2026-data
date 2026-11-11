#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+10;
string c1,s1,c2,s2;
int t1,t2,t3,t4;
int cnt=0;
signed main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int l=c1.size();
	int r=s1.size();
	
	
	for(int i=0;i<l;i++){
		if(c1[i]==c2[i]){
			cnt++;
		}
	}
	if(cnt==l){
		t1=1;
	}else{
		t1=0;
	}
	cnt=0;
	
	
	if(t1==1){
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i]){
				cnt++;
			}
		}
		if(cnt==2){
			t2=1;
		}
		else{
			t2=0;
		}
	}else{
		t2=0;
	}
	cnt=0;
	
	
	if(t2==1){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				t3=1;
			}else{
				t3=0;
			}
		}
		else if(s1[2]=='D'||s1[2]=='F'){
			if(s2[2]=='D'||s2[2]=='F'){
				t3=1;
			}else{
				t3=0;
			}
		}
	}else{
		t3=0;
	}
	
	
	if(t3==1){
		if(s1[2]=='B'||s2[2]=='B'){
			t4=1;
		}
		else if(s1[2]=='D'||s2[2]=='D'){
			t4=1;
		}
	}else{
		t4=0;
	}
	
	
	cout<<t1<<t2<<t3<<t4;
	return 0;
}

