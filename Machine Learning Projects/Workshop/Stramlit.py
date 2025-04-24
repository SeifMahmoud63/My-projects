import streamlit as st
import pickle
import numpy as np

file_path = "D:/workshop/WS.pkl"

with open(file_path, "rb") as f:
    dep = pickle.load(f)

st.title("Life expectancy Prediction")


adult_mortality = st.number_input("Adult Mortality")
bmi = st.number_input("BMI")
hiv_aids = st.number_input("HIV/AIDS")
income_composition = st.number_input("Income Composition of Resources")
schooling = st.number_input("Schooling")
thinness_1_19 = st.number_input("Thinness 1-19 Years")
thinness_5_9 = st.number_input("Thinness 5-9 Years")
polio = st.number_input("Polio")
percentage_expenditure = st.number_input("Percentage Expenditure")
alcohol = st.number_input("Alcohol")

user_input = np.array([[adult_mortality, bmi, hiv_aids, income_composition, schooling, 
                        thinness_1_19, thinness_5_9, polio, percentage_expenditure, alcohol]])

predicted = dep.predict(user_input)

st.success(f"Life expectancy : {predicted[0]}")
