#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int ans=0;
        string s;
	for(int i=1;i<=n;i++){
		while(a[i]>0)s+=c[i],a[i]--;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
/*;
	int sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	int cnti=0,cntj=0;
	//char ch=c[n];
/*
	for(int i=1,j=n;i<j;){
		while(cnti<=cntj&&i<j){
			if(c[i]!=c[j])ans+=min(a[i],cntj-cnti);
			cnti+=a[i];
			i++;
		}
		if(i==j){
			int chax=cnti-sum/2,chay=cntj-sum/2;
			if(chax>=chay){
				int lei=chay-chax;
				while(lei<chay){
					i--;
					lei+=a[i];
					if(c[i]!=c[j])ans+=min(a[i],abs(lei-chay));
				}
				break;
			}else{
				int lei=chax-chay;
                                while(lei<chax){
                                        j++;
                                        lei+=a[j];
                                        if(c[i]!=c[j])ans+=min(a[j],abs(lei-chax));
                                }
                                break;
			}
		}
		while(cnti>cntj&&i<j){
			if(c[i]!=c[j])ans+=min(cnti-cntj,a[j]);
			cntj+=a[j];
			j--;
		}
			if(i==j){
                        int chax=cnti-sum/2,chay=cntj-sum/2;
                        if(chax>=chay){
                                int lei=chay-chax;
                                while(lei<chay){
                                        i--;
                                        lei+=a[i];
                                        if(c[i]!=c[j])ans+=min(a[i],abs(lei-chay));
                                }
                                break;
                        }else{
                                int lei=chax-chay;
                                while(lei<chax){
                                        j++;
                       */
	cout<<ans<<'\n';
	return 0;
}
