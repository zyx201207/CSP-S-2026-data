#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int len;
	char c;
}a[200005];
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	init();
	int l=1,r=n;
	long long ans=0;
	while(1){
		if(a[l].len<a[r].len)swap(a[l],a[r])/*,cout<<"swap\n"*/;
		if(a[l].len==a[r].len&&a[l].c==a[r].c){
			l++,r--;
			continue;
			//cout<<"l++,r--\n";
		}
		if(a[l].c!=a[r].c){
			r--;
			a[l].len-=a[r+1].len;
			if(a[l].len==0)l++/*,cout<<"l++\n"*/;
			ans+=a[r+1].len;/*cout<<"rp++ "<<r+1<<" "*/;
			if(l>=r){
                //cout<<l<<" "<<r<<"\n";
				break;
			}
		}
		else{
            //cout<<"has\n";
			r--;
			a[l].len-=a[r+1].len;
			if(a[l].len==0)l++;
			if(l>=r){
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
