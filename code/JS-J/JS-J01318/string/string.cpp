#include<bits/stdc++.h>
using namespace std;
const int MAXN=200500;
int s1[MAXN];
char s2[MAXN];
int main(){
	freopen("string6.in","r",stdin);
	freopen("string6.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0,cnt=0;
	int pos1=0,pos2=n-1;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		cnt+=s1[i];
	}
	while(cnt>1 and pos1<pos2){
		if(s1[pos1]>=s1[pos2]){
			if(s2[pos1]!=s2[pos2]){
				ans+=s1[pos2];
			}
			cnt-=s1[pos2]*2;
			s1[pos1]-=s1[pos2];
			s1[pos2]-=s1[pos2];
			if(s1[pos1]==0) pos1++;
			if(s1[pos2]==0) pos2--;
		}
		else{
			if(s2[pos1]!=s2[pos2]){
				ans+=s1[pos1];
			}
			cnt-=s1[pos1]*2;
			s1[pos2]-=s1[pos1];
			s1[pos1]-=s1[pos1];
			if(s1[pos1]==0) pos1++;
			if(s1[pos2]==0) pos2--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

