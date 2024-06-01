class ExpertSystem:
    def _init_(self):
        self.symptom_to_disease = {
            'fever': 'Common Cold',
            'cough': 'Bronchitis',
            'headache': 'Migraine',
            # Add more symptoms and corresponding diseases
        }
        self.disease_to_treatment = {
            'Common Cold': 'Rest, Fluids, Over-the-counter medication',
            'Bronchitis': 'Antibiotics, Cough syrup, Inhaler',
            'Migraine': 'Pain relievers, Rest in dark room',
            # Add more diseases and corresponding treatments
        }

    def diagnose(self, symptoms):
        possible_diseases = [self.symptom_to_disease[symptom] for symptom in symptoms if
                             symptom in self.symptom_to_disease]
        if possible_diseases:
            return possible_diseases
        else:
            return ['No specific diagnosis found.']

    def recommend_treatment(self, disease):
        if disease in self.disease_to_treatment:
            return self.disease_to_treatment[disease]
        else:
            return 'No specific treatment recommendation available.'


# Example usage
expert_system = ExpertSystem()

# Take input from user for symptoms
print("Please enter your symptoms (separated by commas):")
patient_symptoms = input().lower().split(',')

# Diagnose patient
diagnoses = expert_system.diagnose(patient_symptoms)
print("Possible diagnoses:", diagnoses)

# Recommend treatment
for disease in diagnoses:
    treatment = expert_system.recommend_treatment(disease)
    print("Treatment for", disease, ":", treatment)