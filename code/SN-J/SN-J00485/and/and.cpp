#include<bits/stdc++.h>
using namespace std;
string a[200000+7];
int num[200000+6];
bool ap[200000+7];
int fl=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,len=-6767;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int in;
		cin>>in;
		int in2=in;
		while(in>0){
			char bt=char(in%2+'0');
			a[i]=bt+a[i];
			in/=2;
		}
		int l=a[i].size();
		len=max(l,len);
//		cout<<a[i]<<'\n';
		num[i]=in2;
		
	}for(int i=1;i<=n;i++){
		int l=a[i].size();
		len=max(l,len);
		for(int j=1;j<=len-l;j++){
			a[i]='0'+a[i];
		}
//		cout<<a[i]<<'\n';
	}
	int ans=0;
	for(int i=0;i<len;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(ap[j]>=2)continue;
			if(a[j][i]=='0')ap[j]=1;
			else cnt++;
		}
		if(cnt==m){
//			cout<<i<<'\n'<<'\n';
			for(int j=1;j<=n;j++){
				if(a[j][i]!='0'){
					if(fl==1){
						ans=num[j];
						fl=0;
					}else{
						ans&=num[j];
					}
//					cout<<num[j]<<" "<<ap[j]<<'\n';
//					cout<<ans<<'\n';
				}
				
			}
		}else if(cnt>m){
			for(int j=1;j<=n;j++){
				if(ap[j])ap[j]+=1;
			}
		}
	}
	cout<<ans;
}//finish!
