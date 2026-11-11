#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,a,b,cnt[200005],cnt1,j,res;
string s,s1;
char c[200005],h;
double t;
bool vis;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cnt[i]>>c[i];
		m+=cnt[i];
	}
	for(int i=0;m>0;i++){
		int d=0;
		if(i>n-j-1){
			break;
		}
		while(d<cnt[i]){
			if(d+cnt[n-j-1]<=cnt[i]){
				res=cnt[n-j-1];
				if(c[i]!=c[n-j-1]){
					cnt1+=res;
				}
				j++;
			}else{
				res=cnt[i]-d;
				cnt[n-j-1]-=res;
				if(c[i]!=c[n-j-1]){
					cnt1+=res;
				}
			}
			m-=res;
			d+=res;
		}
		m-=cnt[i];
	}
	cout<<cnt1; 
	return 0;
	fclose(stdin);
	fclose(stdout);
}
