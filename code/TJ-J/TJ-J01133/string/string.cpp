#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

struct s{
	long long a;
	char c;
};

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long sum=0;
	vector<s> record1(N);
	for(int i=1; i<=n; i++){
		s s1;
		cin >> s1.a >> s1.c;
		record1[i]=s1;
		sum+=s1.a;
	}
	int left=1;
	int right=2;
	vector<s> record2;
	while(left<=n && right<=n){
		if(record1[right].c==record1[left].c){
			record1[left].a+=record1[right].a;
		}else{
			record2.push_back(record1[left]);
			left=right;
		}
		right++;
	}
	record2.push_back(record1[left]);
	int flag=1;
//	for(int i=0; i<record2.size(); i++){
//		cout << record2[i].a << " " << record2[i].c << endl;
//	}
	for(int i=0; i<record2.size()/2; i++){
		s s1=record2[i];
		s s2=record2[record2.size()-(i+1)];
		if(s1.a!=s2.a || s1.c!=s2.c){
			flag=0;
			break;
		}
	}
	
	if(flag==1){
		cout << 0;
	}else{
		long long temp=0;
		int flag1=0;
		long long reduce;
		long long reduce1=0;
		for(int i=0; i<record2.size(); i++){
			temp+=record2[i].a;
			int temp1=0;
			if(temp>=sum/2 && flag1==0){
				reduce=temp-sum/2;
				flag=1;
				break;
			}
			for(int j=record2.size()-1; j>i; j--){
				if(record2[j].c==record2[i].c){
					if(record2[j].a>=temp-record2[i].a && temp1<=temp){
						reduce1+=(record2[j].a-(temp-record2[i].a));
					}else if(temp1>=temp && record2[i].a>=temp1){
						reduce1+=(record2[i].a-temp1);
					}
				}
				temp1+=record2[j].a;
			}
		}
		cout << (sum-reduce)/2-reduce1;
	}
	
	return 0;
}
