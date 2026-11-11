/*
#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
struct qqq{
	int q;
	string w; 
}a[200005];
int cnt=0;
int ans=0;
signed main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].q>>a[i].w;
		ans+=a[i].q;
	}
	int l=1;
	int r=n;
	int ln=1;
	int rn=ans;
	while(ln<=rn){
		if(a[l].w!=a[r].w){
			if(a[l].q==a[r].q){
				cnt+=a[l].q;
				l++;
				r--;
			}else if(a[l].q>a[r].q){
				cnt+=a[r].q;
				rn-=a[r].q;
				int num=a[l].q-a[r].q;
				while(num!=0){
					if(a[r-1].w==a[l].w){
						if(num>=a[r-1].q){
							num-=a[r-1].q;
							rn-=a[r-1].q;
						}else {
							num=0;
							a[r-1].q-=num;
							rn-=num;
						}
					}else {
						if(num>=a[r-1].q){
							cnt+=a[r-1].q;
							num-=a[r-1].q;
							rn-=a[r-1].q;
						}else {
							num=0;
							cnt+=num;
							a[r-1].q-=num;
							rn-=num;
						}
					}
					r--;
				}
			}else if(a[r].q>a[l].q){
				cnt+=a[l].q;
				ln+=a[l].q;
				int num=a[r].q-a[l].q;
				while(num!=0){
					if(a[l+1].w==a[r].w){
						if(num>=a[l+1].q){
							num-=a[l+1].q;
							ln+=a[l+1].q;
						}else {
							num=0;
							a[l+1].q-=num;
							ln+=num;
						}
					}else {
						if(num>=a[l+1].q){
							cnt+=a[l+1].q;
							num-=a[l+1].q;
							ln+=a[l+1].q;
						}else {
							num=0;
							cnt+=num;
							a[l-1].q-=num;
							ln+=num;
						}
					}
					l++;
				}
			}
		}else {
			if(a[l].q==a[r].q){
				ln+=a[l].q;
				rn-=a[r].q;
				l++;
				r--;
			}else if(a[l].q>a[r].q){
				ln+=a[l].q;
				rn-=a[r].q;
				r--; 
			}else if(a[r].q>a[l].q){
				ln+=a[l].q;
				rn-=a[r].q;
				l++; 
			} 
		}
	}
	cout<<cnt;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}


*/
#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
string m;
string x,y;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int q;
		string w;
		cin>>q>>w;
		string u;
		for(int i=1;i<=q/2;i++){
			u+=w;
		}
		if(q%2==0){
			m=m+u+u;
		}else m=m+u+u+w;
	}
	if(m.size()%2==0){
		for(int i=0;i<m.size()/2;i++){
			x=x+m[i];
		}
		for(int i=m.size()/2;i<m.size();i++){
			y=y+m[i];
		}
		int cnt=0;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				cnt++;
			}
		}
		cout<<cnt;
	}else {
		for(int i=1;i<=m.size()/2;i++){
			x=x+m[i];
		}
		for(int i=m.size()/2+1;i<=m.size();i++){
			y=y+m[i];
		}
		int cnt=0;
		for(int i=1;i<=x.size();i++){
			if(x[i]!=y[i]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	//cout<<x<<endl<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
/*
4
2 q
2 w
2 w
1 q
*/	
	
	
	
	
	
