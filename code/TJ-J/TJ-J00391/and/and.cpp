#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s[200010] = {};
	long long num,max = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> s[i];
	} 
	for (int a = 0;a < n;a++){
		for (int b = a + 1;b < n;b++){
			if (m > 2){
				for (int c = b + 1;c < n;c++){
					if (m > 3){
						for (int d = c + 1;d < n;d++){
							if (m > 4){
								for (int e = d + 1;e < n;e++){
									if (m > 5){
										for (int f = e + 1;f < n;f++){
											if (m > 6){
												for (int g = f + 1;g < n;g++){
													if (m > 7){
														for (int h = g + 1;h < n;h++){
															if (m > 8){
																for (int i = h + 1;i < n;i++){
																	if (m > 9){
																		for (int j = i + 1;j < n;j++){
																			if (m > 10){
																				for (int k = j + 1;k < n;k++){
																					if (m > 11){
																						for (int l = k + 1;l < n;l++){
																							if (m > 12){
																								for (int o = l + 1;o < n;o++){
																									if (m > 12){
																										for (int p = o + 1;p < n;p++){
																											if (m > 13){
																												for (int q = p + 1;q < n;q++){
																													if (m > 14){
																														for (int r = q + 1;r < n;r++){
																															if (m > 15){
																																for (int t = r + 1;t < n;t++){
																																	if (m > 17){
																																		for (int u = t + 1;u < n;u++){
																																			if (m > 18){
																																				for (int v = u + 1;v < n;v++){
																																					if (m > 19){
																																						for (int w = v + 1;w < n;w++){
																																							if (m > 20){
																																								for (int x = w + 1;x < n;x++){
																																									if (m > 21){
																																										cout << max;
																																										return 0;
																																									} 
																																									else{
																																										num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k] & s[l] & s[o] & s[p] & s[q] & s[r] & s[t] & s[u] & s[v] & s[w] & s[x];
																																										if (max < num){
																																											max = num;
																																										} 
																																									} 
																																								} 
																																							} 
																																							else{
																																								num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k] & s[l] & s[o] & s[p] & s[q] & s[r] & s[t] & s[u] & s[v] & s[w];
																																								if (max < num){
																																									max = num;
																																								} 
																																							} 
																																						} 
																																					} 
																																					else{
																																						num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k] & s[l] & s[o] & s[p] & s[q] & s[r] & s[t] & s[u] & s[v];
																																						if (max < num){
																																							max = num;
																																						} 
																																					} 
																																				} 
																																			} 
																																			else{
																																				num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k] & s[l] & s[o] & s[p] & s[q] & s[r] & s[t] & s[u];
																																				if (max < num){
																																					max = num;
																																				} 
																																			} 
																																		} 
																																	} 
																																	else{
																																		num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k] & s[l] & s[o] & s[p] & s[q] & s[r] & s[t];
																																		if (max < num){
																																			max = num;
																																		} 
																																	} 
																																} 
																															} 
																															else{
																																num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k] & s[l] & s[o] & s[p] & s[q] & s[r];
																																if (max < num){
																																	max = num;
																																} 
																															} 
																														} 
																													} 
																													else{
																														num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k] & s[l] & s[o] & s[p] & s[q];
																														if (max < num){
																															max = num;
																														} 
																													} 
																												} 
																											} 
																											else{
																												num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k] & s[l] & s[o] & s[p];
																												if (max < num){
																													max = num;
																												} 
																											} 
																										} 
																									} 
																									else{
																										num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k] & s[l] & s[o];
																										if (max < num){
																											max = num;
																										} 
																									} 
																								} 
																							} 
																							else{
																								num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k] & s[l];
																								if (max < num){
																									max = num;
																								} 
																							} 
																						} 
																					} 
																					else{
																						num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j] & s[k];
																						if (max < num){
																							max = num;
																						} 
																					} 
																				} 
																			} 
																			else{
																				num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i] & s[j];
																				if (max < num){
																					max = num;
																				} 
																			} 
																		} 
																	} 
																	else{
																		num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h] & s[i];
																		if (max < num){
																			max = num;
																		} 
																	} 
																} 
															} 
															else{
																num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g] & s[h];
																if (max < num){
																	max = num;
																} 
															} 
														} 
													} 
													else{
														num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f] & s[g];
														if (max < num){
															max = num;
														} 
													} 
												} 
											} 
											else{
												num = s[a] & s[b] & s[c] & s[d] & s[e] & s[f];
												if (max < num){
													max = num;
												} 
											} 
										} 
									} 
									else{
										num = s[a] & s[b] & s[c] & s[d] & s[e];
										if (max < num){
											max = num;
										} 
									} 
								} 
							} 
							else{
								num = s[a] & s[b] & s[c] & s[d];
								if (max < num){
									max = num;
								} 
							} 
						} 
					} 
					else{
						num = s[a] & s[b] & s[c];
						if (max < num){
							max = num;
						} 
					} 
				} 
			} 
			else{
				num = s[a] & s[b];
				if (max < num){
					max = num;
				} 
			} 
		} 
	} 
	cout << max;
	return 0;
} 
