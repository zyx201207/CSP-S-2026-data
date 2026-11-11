#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int arr[500005],brr[500005];
set<int>st1,st2; 
int cnt[500005]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		brr[i]=arr[i];
	}
	sort(brr+1,brr+n+1);
	int tot=unique(brr+1,brr+n+1)-brr-1;
	for(int i=1;i<=n;i++){
		arr[i]=lower_bound(brr+1,brr+tot+1,arr[i])-brr;
	}
	int l=1,z=brr[1],sum=0,ans=0,ct=0,dct=0,lct=0;
	for(int i=1;i<=n;i++){
		sum+=abs(brr[arr[i]]-z);
		st1.insert(brr[arr[i]]);
		cnt[arr[i]]++;
		st2.insert(-brr[arr[i]]);
		if(brr[arr[i]]==z){
			ct++;
		}
		if((i-l+1)%2==1 && (i-l+1)!=1){
			if(lct){
				ct++;
				lct--;
			}else if(ct>1){
				ct--;
				dct++;
			}else{
				if(brr[arr[i]]>z){
					auto tmp=st1.lower_bound(z+1); 
					int temp=*tmp;
					sum-=temp-z;
					z=temp;
					ct=lower_bound(brr+1,brr+tot+1,z)-brr;
					ct=cnt[ct];
					dct=0;
					lct=0;
				}else{
					auto tmp=st2.lower_bound(-z-1); 
					int temp=*tmp;
					sum-=z+temp;
					z=-temp;
					ct=lower_bound(brr+1,brr+tot+1,z)-brr;
					ct=cnt[ct];
					dct=0;
					lct=0;
				}
			} 
		}
//		cout<<z<<' '<<sum<<'\n';
		while(sum>m){
			sum-=abs(z-brr[arr[l]]);
			cnt[arr[l]]--;
			if(cnt[arr[l]]==0){
				st1.erase(brr[arr[l]]);
				st2.erase(-brr[arr[l]]);
			}
//			cout<<l<<' '<<sum<<'\n';
			if((i-l)%2==1 && i-l!=1){
				if(dct){
					dct--;
					ct++;
				}else if(ct>1){
					ct--;
					lct++;
				}else{
					if(brr[arr[l]]>z){
						auto tmp=st2.lower_bound(-z-1); 
						int temp=*tmp;
						sum-=z+temp;
						z=-temp;
						ct=lower_bound(brr+1,brr+tot+1,z)-brr;
						ct=cnt[ct];
						dct=0;
						lct=0;
					}else{
						auto tmp=st1.lower_bound(z+1); 
						int temp=*tmp;
						sum-=temp-z;
						z=temp;
						ct=lower_bound(brr+1,brr+tot+1,z)-brr;
						ct=cnt[ct];
						dct=0;
						lct=0;
					}
				}
			}
			l++;
		}
//		cout<<l<<' '<<z<<' '<<sum<<'\n';
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
难道真的燃尽了吗，退役吧
T1没切出来
害
J组批发保分符的那个入

luogu:yiwugougou

希望大家都忘早点了我吧 

yiwugougou是我赢了
出题人，恕我直言，我没有看出你哪里赢了
爱卿请看，我让你在30min后想到了T1思路，但是让你卡在了logn求中位数上，并且调了2.5h没有调出来，是我赢了
我************ccf 

last:?pts+32pts+8pts+0pts=?+40pts
*/
