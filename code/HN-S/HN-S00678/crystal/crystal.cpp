#include<bits/stdc++.h>
using namespace std;
//先Rp++,还有和xyh99呢
//丧失个性跟去死没区别呢 ——凉 
long long n,m;
vector<long long>a;
struct xyh {
	long long y,s;
	bool operator<( const xyh &y) const {
		return s > y.s;
	}
};//这段忘了还是从报错跳出来的stl_function.h抄的
priority_queue<xyh>spends;
//void debugs() {
//	while(spends.size()>0) {
//		cout<<spends.top().y<<endl;
//		spends.pop();
//	}
//	cout<<"debugs done";
//	return;
//}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//神秘CCF14:33才发密码
	//Oct31==Dec25?
	//这屏幕真tm小
	long long n,m,halfp;
	cin>>n>>m;
	halfp=n/2;
	for(int i=0; i<n; i++) {
		int t;
		cin>>t;
		a.push_back(t);
		
	}
	if(m==0) {
		cout<<1;
		return 0;
	}
	long long m1=m,use1=0;
	long long ans1=1;
	sort(a.begin(),a.end());
	long long half=a[halfp],l=1,r=1;
	//debugs
	//cout<<a.size();
	//for(int i=0; i<n; i++)cout<<a[i]<<endl;
	//cout<<half<<endl;
	for(int i=halfp; i<n; i++) {
		//cout<<ans1;
		if(m1>=abs(half-abs(a[(halfp)-l]))) {
			//cout<<m1<<" "<<abs(half-abs(a[(halfp)-l]))<<endl;
			//cout<<a[(halfp)-l]<<" ";
			//debug
			struct xyh temp1;
			temp1.y=a[(halfp)-l];
			temp1.s=abs(half-abs(a[(halfp)-l]));
			spends.push(temp1);
			use1+=abs(half-abs(a[(halfp)-l]));
			m1-=abs(half-abs(a[(halfp)-l]));
			a[(halfp)-l]+=abs(half-abs(a[(halfp)-l]));
			l++;
			ans1++;
		} else {
			//cout<<ans1<<endl;
			while(1) {
				long long need=(ans1-1)*(a[(halfp)+r]-half);
				if(need<m1) {
					struct xyh t1;
					t1.y=a[i];
					t1.s=a[i+1]-a[i];
					ans1++;
					r++;
					m1-=a[i+1]-a[i];
				}
				if((!spends.empty() && spends.top().s>=need) || need==0) {
					//cout<<need<<"\n";
					if(!spends.empty()) {
						a[(halfp)-l+1]=spends.top().y;
						m1+=spends.top().s;
						m1-=need;
						spends.pop();
						r++;
					} else {
						if(a[(halfp)+r]-half<m1) {
							m1-=a[(halfp)+r]-half;
						} else {
							for(int i=0; i<n; i++) {
								if(a[i+1]-a[i]<m1) {
									halfp=i;
									struct xyh t1;
									t1.y=a[i];
									t1.s=a[i+1]-a[i];
									ans1++;
									r++;
									m1-=a[i+1]-a[i];
									break;
								}
							}
						}
					}
				} else {
					//debugs();
					cout<<ans1;
					return 0;
				}
			}
		}//神秘CCF 15:01 P.M. 打了个考试开始的铃,难绷
		//你m的有人给我发信息就一直弹我能打上海major的铃声(完美电竞平台那个),md,好失格
	}
	//debugs();
	cout<<ans1;
	return 0;
}/*
5 5
1 2 4 8 9
*//*
5 8
-3 -1 2 2 7
*//*
5 8
-999 -999 1 2 3
*/
