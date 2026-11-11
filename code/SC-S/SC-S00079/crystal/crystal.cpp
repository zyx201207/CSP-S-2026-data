//崔SH，我把你写进代码里，希望你能保佑我过
#include<bits/stdc++.h>
using namespace std;
constexpr int TONG_MAX=1e5+5;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//测试一定要加
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	int n;
	unsigned long long m;
	scanf("%d%lld",&n,&m);
	long long a[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	vector<vector<long long>>s;
	long long cnt=0;
	s.push_back({cnt,a[0]});
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1])
			s.push_back({cnt,a[i]});
		else
			s.push_back({++cnt,a[i]});
	}
	//测试
//	printf("ok");
	//s数组里0对应编号，second对应原数
	vector<vector<long long>> tong(cnt+1);
	for(int i=0;i<=cnt;i++){
		tong[i].resize(3);
	}
//	//测试
//	printf("ok");
//	for(int i=0;i<n;i++){
//		printf("%d\n",s[i][0]);
//	}
	for(long long i=0;i<s.size();i++){
		tong[s[i][0]][0]++,tong[s[i][0]][1]=s[i][0],tong[s[i][0]][2]=s[i][1];
	}
//	printf("ok\n");
	//tong数组里0对应数量，1对应编号，2对应原数
//测试
//	printf("ok");
//	printf("%lld\n",tong[0][0]);
	//对tong排序
//	sort(tong.begin(),tong.end(),cmp);
//	printf("%lld\n",tong[0][0]);
//	//测试
//	for(int i=0;i<int(tong.size());i++){
//		printf("%lld %lld %lld\n",tong[i][0],tong[i][1],tong[i][2]);
//	}
	//测试
	long long length=tong.size();
//	printf("%lld %lld",cnt,length);
	long long ans=0;
	for(long long i=0;i<length;i++){
		long long max_num=tong[i][0];
		long long k=m;
//		for(long long j=0;j<i;j++){
//			if(i==j){
//				continue;
//			} 
//			if(tong[j][2]>=tong[i][2]){
//				continue;
//			}
//			long long cha=tong[i][2]-tong[j][2];
//			if(k>=cha){
//				k-=cha,max_num++;
//			}
//			if(k==0) break;
//		}
		for(long long j=0;j<n;j++){
			if(tong[i][2]<=a[j]) continue;
			long long cha=tong[i][2]-a[j];
			if(k>=cha){
				k-=cha,max_num++;
			}
			if(k==0) break;
		}
		ans=max(ans,max_num);
	}
	printf("%lld\n",ans);
	return 0;
} 