#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,c[214514],sum,ans;
pair<int,char> q1[214514],q2[211411];
map<int,pair<int,char> >mp,mp2;
map<int,bool>vis;
char s[214514];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>s[i];
		sum+=c[i];
	}int cnt1=0,cnt2=0;
	if(sum<=2000000){
		string st;
		for(int i=1;i<=n;i++){
			for(int j=0;j<c[i];j++)st=st+s[i];
		}for(int i=0,j=st.size()-1;i<j;i++,j--){
			if(st[i]!=st[j]) ans++;
		}return cout<<ans,0;
	}
	if(sum%2==1){
		int mid=(sum+1)/2;
		sum=0;
		for(int i=1;i<=n;i++){
			sum+=c[i];
			if(sum>=mid){
				q1[0]={mid-sum+c[i]-1,s[i]};
				q2[0]={sum-mid,s[i]};
				mp[q1[0].first]={cnt1,s[i]};
				mp2[q2[0].first]={cnt2,s[i]};
				for(int j=i-1;j>=1;j--){
					q1[i-j]={q1[i-j-1].first+c[j],s[j]};
					cnt1++;
					mp[q1[i-j].first]={cnt1,s[j]};
				}for(int j=i+1;j<=n;j++){
					q2[j-i]={q2[j-i-1].first+c[j],s[j]};
					cnt2++;
					mp2[q2[j-i].first]={cnt2,s[j]};
				}break;
			}
		}
	}else{
		int mid=sum/2;
		sum=0;
		for(int i=1;i<=n;i++){
			sum+=c[i];
			if(sum>=mid){
				q1[0]={mid+1-sum+c[i]-1,s[i]};
				q2[0]={sum-mid,s[i]};
				mp[q1[0].first]={cnt1,s[i]};
				mp2[q2[0].first]={cnt2,s[i]};
				for(int j=i-1;j>=1;j--){
					q1[i-j]={q1[i-j-1].first+c[j],s[j]};
					cnt1++;
					mp[q1[i-j].first]={cnt1,s[j]};
				}for(int j=i+1;j<=n;j++){
					q2[j-i]={q2[j-i-1].first+c[j],s[j]};
					cnt2++;
					mp2[q2[j-i].first]={cnt2,s[j]};
				}break;
			}
		}
	}
	vector<int> num;
	for(int i=0;i<=cnt1;i++){
		num.push_back(q1[i].first);
		vis[q1[i].first]=1;
	}for(int i=0;i<=cnt2;i++)if(!vis[q2[i].first])num.push_back(q2[i].first);
	sort(num.begin(),num.end());
	int pre1=-1,pre2=-1;
	for(int i=0;i<num.size();i++){
		if(mp2.count(num[i])&&mp.count(num[i])){
			pre1=mp[num[i]].first,pre2=mp2[num[i]].first;
			if(mp2[num[i]].second!=mp[num[i]].second){
				ans+=num[i];
				if(i!=0) ans-=num[i-1];
			}
		}else if(mp2.count(num[i])){
			pre2=mp2[num[i]].first;
			char a=q1[pre1+1].second;
			if(i==5) cout<<a<<" "<<mp2[num[i]].second<<endl;
			if(a!=mp2[num[i]].second){
				ans+=num[i];
				if(i!=0) ans-=num[i-1];
			}
		}else{
			pre1=mp[num[i]].first;
			char a=q2[pre2+1].second;
			if(a!=mp2[num[i]].second){
				ans+=num[i];
				if(i!=0) ans-=num[i-1];
			}			
		}
	}cout<<ans;
	return 0;
} 
/*
8
3 a
1 b
3 c
3 d
2 c
2 d
2 a
2 c
*/
