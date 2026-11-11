#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	long long maxn=0;
	long long c[2001];
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	if(b==1){
		for(int i=1;i<=a;i++){
			maxn=max(c[i],maxn);
		}
	}
	if(b==2){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				maxn=max(maxn,c[i]&c[i1]);
			}
		}
	}
	if(b==3){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					maxn=max(maxn,c[i]&c[i1]&c[i2]);
				}
			}
		}
	}
	if(b==4){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]);
					}
				}
			}
		}
	}
	if(b==5){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]);
						}
					}
				}
			}
		}
	}
	if(b==6){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]);
							}
						}
					}
				}
			}
		}
	}
	if(b==7){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]);
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==8){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==9){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==10){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==11){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												for(int i10=i9+1;i10<=a;i10++){
													maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]&c[i10]);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==12){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												for(int i10=i9+1;i10<=a;i10++){
													for(int i11=i10+1;i11<=a;i11++){
														maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]&c[i10]&c[i11]);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==13){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												for(int i10=i9+1;i10<=a;i10++){
													for(int i11=i10+1;i11<=a;i11++){
														for(int i12=i11+1;i12<=a;i12++){
															maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]&c[i10]&c[i11]&c[i12]);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==14){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												for(int i10=i9+1;i10<=a;i10++){
													for(int i11=i10+1;i11<=a;i11++){
														for(int i12=i11+1;i12<=a;i12++){
															for(int i13=i12+1;i13<=a;i13++){
																maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]&c[i10]&c[i11]&c[i12]&c[i13]);
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==15){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												for(int i10=i9+1;i10<=a;i10++){
													for(int i11=i10+1;i11<=a;i11++){
														for(int i12=i11+1;i12<=a;i12++){
															for(int i13=i12+1;i13<=a;i13++){
																for(int i14=i13+1;i14<=a;i14++){
																	maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]&c[i10]&c[i11]&c[i12]&c[i13]&c[i14]);
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==16){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												for(int i10=i9+1;i10<=a;i10++){
													for(int i11=i10+1;i11<=a;i11++){
														for(int i12=i11+1;i12<=a;i12++){
															for(int i13=i12+1;i13<=a;i13++){
																for(int i14=i13+1;i14<=a;i14++){
																	for(int i15=i14+1;i15<=a;i15++){
																		maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]&c[i10]&c[i11]&c[i12]&c[i13]&c[i14]&c[i15]);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==17){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												for(int i10=i9+1;i10<=a;i10++){
													for(int i11=i10+1;i11<=a;i11++){
														for(int i12=i11+1;i12<=a;i12++){
															for(int i13=i12+1;i13<=a;i13++){
																for(int i14=i13+1;i14<=a;i14++){
																	for(int i15=i14+1;i15<=a;i15++){
																		for(int i16=i15+1;i16<=a;i16++){
																			maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]&c[i10]&c[i11]&c[i12]&c[i13]&c[i14]&c[i15]&c[i16]);
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==18){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												for(int i10=i9+1;i10<=a;i10++){
													for(int i11=i10+1;i11<=a;i11++){
														for(int i12=i11+1;i12<=a;i12++){
															for(int i13=i12+1;i13<=a;i13++){
																for(int i14=i13+1;i14<=a;i14++){
																	for(int i15=i14+1;i15<=a;i15++){
																		for(int i16=i15+1;i16<=a;i16++){
																			for(int i17=i16+1;i17<=a;i17++){
																				maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]&c[i10]&c[i11]&c[i12]&c[i13]&c[i14]&c[i15]&c[i16]&c[i17]);
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==19){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												for(int i10=i9+1;i10<=a;i10++){
													for(int i11=i10+1;i11<=a;i11++){
														for(int i12=i11+1;i12<=a;i12++){
															for(int i13=i12+1;i13<=a;i13++){
																for(int i14=i13+1;i14<=a;i14++){
																	for(int i15=i14+1;i15<=a;i15++){
																		for(int i16=i15+1;i16<=a;i16++){
																			for(int i17=i16+1;i17<=a;i17++){
																				for(int i18=i17+1;i18<=a;i18++){
																					maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]&c[i10]&c[i11]&c[i12]&c[i13]&c[i14]&c[i15]&c[i16]&c[i17]&c[i18]);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==20){
		for(int i=1;i<=a;i++){
			for(int i1=i+1;i1<=a;i1++){
				for(int i2=i1+1;i2<=a;i2++){
					for(int i3=i2+1;i3<=a;i3++){
						for(int i4=i3+1;i4<=a;i4++){
							for(int i5=i4+1;i5<=a;i5++){
								for(int i6=i5+1;i6<=a;i6++){
									for(int i7=i6+1;i7<=a;i7++){
										for(int i8=i7+1;i8<=a;i8++){
											for(int i9=i8+1;i9<=a;i9++){
												for(int i10=i9+1;i10<=a;i10++){
													for(int i11=i10+1;i11<=a;i11++){
														for(int i12=i11+1;i12<=a;i12++){
															for(int i13=i12+1;i13<=a;i13++){
																for(int i14=i13+1;i14<=a;i14++){
																	for(int i15=i14+1;i15<=a;i15++){
																		for(int i16=i15+1;i16<=a;i16++){
																			for(int i17=i16+1;i17<=a;i17++){
																				for(int i18=i17+1;i18<=a;i18++){
																					for(int i19=i18+1;i19<=a;i19++){
																						maxn=max(maxn,c[i]&c[i1]&c[i2]&c[i3]&c[i4]&c[i5]&c[i6]&c[i7]&c[i8]&c[i9]&c[i10]&c[i11]&c[i12]&c[i13]&c[i14]&c[i15]&c[i16]&c[i17]&c[i18]&c[i19]);
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}