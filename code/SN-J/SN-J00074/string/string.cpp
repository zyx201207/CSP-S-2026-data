#include<bits/stdc++.h>
using namespace std;
/*(struct chs{
	unsigned long long l=0,r=0;
	char c='0';
};
vector<chs>str;*/
int main(){
	unsigned long long n=0;cin>>n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	/*unsigned long long n=0;cin>>n;
	unsigned long long now_pos=0;
	for(unsigned long long i=0;i<n;i++){
		unsigned long long a=0;char b='0';cin>>a>>b;
		unsigned long long left=now_pos;
		now_pos+=a;
		unsigned long long right=now_pos;
		chs c={left,right,b};
		str.push_back(c);
	}
	unsigned long long s=now_pos;
	long long left=-1,right=s,ans=0;
	while(right>left+1){
		unsigned long long mid=(left+right)/2;
		if(str[mid].right<=mid){
			right=mid;
		}
		else if(str[mid].left>mid){
			left=mid;
		}
		else{
			ans=mid;
			break;
		}
	}
	cout<<ans;*/
	string S;
	for(unsigned long long i=0;i<n;i++){
		unsigned long long a=0;char b='0';cin>>a>>b;
		S.append(a,b);
	} 
	signed long long pos=S.size()/2;
	unsigned long long p2=S.size()%2==0?S.size()/2:S.size()/2+1;
	string s1=S.substr(0,pos);
	string s2=S.substr(p2,pos);
	//cout<<s1<<' '<<s2;
	unsigned long long cnt=0;
	for(unsigned long long i=0;i<pos;i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
