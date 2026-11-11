#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<pair<int,char>>v;
int he;
string s;
int cishu;
int zong;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){//cin
		int x;char y;
		cin>>x;
		cin>>y;
		v.push_back({x,y});
		he+=x;
	}
	if(he%2==0){
		int er=he/2;
		int i=0,j=v.size()-1;
		int qian=0,hou=0;
		char qiann,houn;
		while(zong<er&&i!=j){
			if(qian==0&&hou==0){
				if(v[i].first-v[j].first>0){
					qian=v[i].first-v[j].first;
					zong+=v[i].first-qian;
					qiann=v[i].second;
					if(v[i].second!=v[j].second){
						cishu+=v[j].first;
					}
					j--;
				}else if(v[i].first-v[j].first<0){
					hou=abs(v[i].first-v[j].first);
					houn=v[j].second;
					zong+=v[i].first;
					if(v[i].second!=v[j].second){
						cishu+=v[i].first;
					}
					i++;
				}else if(v[i].first-v[j].first==0){
					zong+=v[i].first;
					if(v[i].second!=v[j].second){
						cishu+=v[i].first;//=v[j].first;
					}
					i++,j--;
				}
			}
			else if(qian!=0&&hou==0){
				if(qian-v[j].first>0){
					zong+=v[j].first;
					qian=qian-v[j].first;
					if(qiann!=v[j].second){
						cishu+=v[j].first;
					}
					j--;
				}else if(qian-v[j].first<0){
					hou=abs(qian-v[j].first);
					houn=v[j].second;
					if(qiann!=v[j].second){
						cishu+=qian;
					}
					zong+=qian;
					qian=0;qiann='\0';
					i++;
				}else if(qian-v[j].first==0){
					zong+=qian;
					qian=0;qiann='\0';
					if(v[i].second!=v[j].second){
						cishu+=qian;//=v[j].first;
					}
					i++,j--;
				}
			}else if(qian==0&&hou!=0){
				if(v[i].first-hou>0){
					qian=v[i].first-hou;
					zong+=hou;
					qiann=v[i].second;
					if(v[i].second!=houn){
						cishu+=hou;
					}
					j--;
					hou=0;houn='\0';
				}else if(v[i].first-hou<0){
					hou-=v[i].first;
					zong+=v[i].first;
					if(v[i].second!=v[j].second){
						cishu+=v[i].first;
					}
					i++;
				}else if(v[i].first-hou==0){
					hou=0;houn='\0';
					zong+=v[i].first;
					if(v[i].second!=v[j].second){
						cishu+=v[i].first;//=v[j].first;
					}
					i++,j--;
				}
			}
			
		}
	}
	else{
		int er=he/2+1;
		int i=0,j=v.size()-1;
		int qian=0,hou=0;
		char qiann,houn;
		while(zong<er&&i!=j){
			if(i==j){
				break;
			}
			if(qian==0&&hou==0){
				if(v[i].first-v[j].first>0){
					qian=v[i].first-v[j].first;
					zong+=v[i].first-qian;
					qiann=v[i].second;
					if(v[i].second!=v[j].second){
						cishu+=v[j].first;
					}
					j--;
				}else if(v[i].first-v[j].first<0){
					hou=abs(v[i].first-v[j].first);
					houn=v[j].second;
					zong+=v[i].first;
					if(v[i].second!=v[j].second){
						cishu+=v[i].first;
					}
					i++;
				}else if(v[i].first-v[j].first==0){
					zong+=v[i].first;
					if(v[i].second!=v[j].second){
						cishu+=v[i].first;//=v[j].first;
					}
					i++,j--;
				}
			}
			else if(qian!=0&&hou==0){
				if(qian-v[j].first>0){
					zong+=v[j].first;
					qian=qian-v[j].first;
					if(qiann!=v[j].second){
						cishu+=v[j].first;
					}
					j--;
				}else if(qian-v[j].first<0){
					hou=abs(qian-v[j].first);
					houn=v[j].second;
					if(qiann!=v[j].second){
						cishu+=qian;
					}
					zong+=qian;
					qian=0;qiann='\0';
					i++;
				}else if(qian-v[j].first==0){
					zong+=qian;
					qian=0;qiann='\0';
					if(v[i].second!=v[j].second){
						cishu+=qian;//=v[j].first;
					}
					i++,j--;
				}
			}else if(qian==0&&hou!=0){
				if(v[i].first-hou>0){
					qian=v[i].first-hou;
					zong+=hou;
					qiann=v[i].second;
					if(v[i].second!=houn){
						cishu+=hou;
					}
					j--;
					hou=0;houn='\0';
				}else if(v[i].first-hou<0){
					hou-=v[i].first;
					zong+=v[i].first;
					if(v[i].second!=v[j].second){
						cishu+=v[i].first;
					}
					i++;
				}else if(v[i].first-hou==0){
					hou=0;houn='\0';
					zong+=v[i].first;
					if(v[i].second!=v[j].second){
						cishu+=v[i].first;//=v[j].first;
					}
					i++,j--;
				}
			}
			
		}
	}
	cout<<cishu;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
