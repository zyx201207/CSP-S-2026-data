#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<long long> nums;
	for(int i=0; i<n; i++){
		int card;
		cin >> card;
		nums.push_back(card);
	}
	vector<long long> results(m+5, 0);
	int round[n+5];
	int times[m+5];
	int t_r[m+5];
	for(int i=0; i<n; i++){
		memset(times, 0, sizeof(times));
		memset(round, 0, sizeof(times));
		memset(t_r, 0, sizeof(times));
		for(int j=i; j<n; j++){
			if(times[nums[j]]!=0){
				int turn=t_r[nums[j]];
				for(int z=turn; z<=j+1; z++){
					times[round[z]]=0;
					t_r[round[z]]=0;
					round[z]=0;
				}
			}
			times[nums[j]]=1;
			round[j+1]=nums[j];
			t_r[nums[j]]=j+1;
		}
		for(int k=1; k<=m; k++){
			if(times[k]!=0){
				results[k]++;
			}
		}
	}
	for(int i=1; i<=m; i++){
		cout << results[i] << " ";
	}
	
	return 0;
}
